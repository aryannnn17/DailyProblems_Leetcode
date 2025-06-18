class Solution {
    typedef long long ll;
    int MOD = 1e9 + 7;

    int binaryExp(ll a, ll b) {
        ll res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return res;
    }

public:
    int countGoodArrays(int n, int m, int k) {

        vector<int> fact(n + 1);
        vector<int> inv_fact(n + 1);
        fact[0] = 1;

        for (int i = 1; i <= n; ++i)
            fact[i] = (1LL * i * fact[i - 1]) % MOD;

        inv_fact[n] = binaryExp(fact[n], MOD - 2);
        for (int i = n; i > 0; --i)
            inv_fact[i - 1] = (1LL * inv_fact[i] * i) % MOD;

        int ways1 =
            ((1LL * fact[n - 1] * inv_fact[n - k - 1]) % MOD * inv_fact[k]) %
            MOD;
        int ways2 = (1LL * m * binaryExp(m - 1, n - k - 1)) % MOD;
        return (1LL * ways1 * ways2) % MOD;
    }
};
