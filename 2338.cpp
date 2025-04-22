class Solution {

    long count[15][10005];
    long preSum[15][10005];
    long opt[15];
    int MOD = 1e9 + 7;

    void cntSeq(int curr, int idx, int& maxValue) {
        opt[idx] += 1;
        for (int j = 2; curr * j <= maxValue; ++j)
            cntSeq(curr * j, idx + 1, maxValue);
    }

public:
    int idealArrays(int n, int maxValue) {

        memset(count, 0, sizeof(count));
        memset(preSum, 0, sizeof(preSum));
        memset(opt, 0, sizeof(opt));

        for (int i = 1; i <= 10000; ++i) {
            count[1][i] = 1;
            preSum[1][i] = i;
        }

        for (int i = 2; i <= 14; ++i) {
            for (int j = i; j <= 10000; ++j) {
                count[i][j] = preSum[i - 1][j - 1];
                preSum[i][j] = count[i][j] + preSum[i][j - 1];
                count[i][j] %= MOD;
                preSum[i][j] %= MOD;
            }
        }

        for (int i = 1; i <= maxValue; ++i)
            cntSeq(i, 1, maxValue);
        long ans = 0;
        long ways;
        for (int i = 1; i <= 14; ++i) {
            ways = count[i][n] * opt[i];
            ways %= MOD;
            ans += ways;
            ans %= MOD;
        }
        return ans;
    }
};
