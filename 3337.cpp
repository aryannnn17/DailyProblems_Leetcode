class Solution {
    typedef vector<vector<int>> Matrix;
    int MOD = 1e9 + 7;

    Matrix matrixMultiplication(const Matrix& A, const Matrix& B) {
        Matrix ans(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                for (int k = 0; k < 26; ++k)
                    ans[i][j] =
                        (ans[i][j] + (1LL * A[i][k] * B[k][j]) % MOD) % MOD;

        return ans;
    }

    Matrix matrixExponentiation(const Matrix& base, int exponent) {

        if (exponent == 0) {
            Matrix identity(26, vector<int>(26, 0));
            for (int i = 0; i < 26; ++i)
                identity[i][i] = 1;
            return identity;
        }
        Matrix half = matrixExponentiation(base, exponent / 2);
        Matrix ans = matrixMultiplication(half, half);
        if (exponent % 2 == 1)
            ans = matrixMultiplication(ans, base);
        return ans;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> freq(26, 0);
        for (char& c : s)
            freq[c - 'a']++;

        Matrix T(26, vector<int>(26, 0));
        for (int i = 0; i < 26; ++i)
            for (int add = 1; add <= nums[i]; ++add)
                T[(i + add) % 26][i]++;

        Matrix ans = matrixExponentiation(T, t);
        vector<int> updated_freq(26, 0);
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                updated_freq[i] =
                    (updated_freq[i] + (1LL * ans[i][j] * freq[j]) % MOD) % MOD;

        int ret = 0;
        for (int i = 0; i < 26; ++i)
            ret = (ret + updated_freq[i]) % MOD;

        return ret;
    }
};
