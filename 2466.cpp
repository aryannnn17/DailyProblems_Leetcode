// class Solution {
//     int dp[100001], MOD = 1000000007;
//     int countWays(int& low, int& high, int& zero, int& one, int idx) {
//         if (idx > high)
//             return 0;
//         if (dp[idx] != -1)
//             return dp[idx];
//         int count = 0;
//         if (idx >= low)
//             count++;
//         count += countWays(low, high, zero, one, idx + zero);
//         count += countWays(low, high, zero, one, idx + one);
//         return dp[idx] = count % MOD;
//     }

// public:
//     int countGoodStrings(int low, int high, int zero, int one) {
//         memset(dp, -1, sizeof(dp));
//         return countWays(low, high, zero, one, 0);
//     }
// };


class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        int ans = 0,mod = 1000000007;
        dp[0] = 1;
        for (int i = 1; i <= high; i++) {
            if (i >= zero)
                dp[i] += dp[i - zero];
            if (i >= one)
                dp[i] += dp[i - one];
            dp[i] %= mod ;
            if (i >= low) {
                ans += dp[i];
                ans %= mod;
            }  
        }
        return ans;
    }
};
