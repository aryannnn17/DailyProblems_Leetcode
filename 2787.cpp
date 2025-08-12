class Solution {
public:
    int M = 1e9 + 7;
    int t[301][301];
    int func(int n, int num, int x) {
        if (n == 0)
            return 1;
        else if (n < 0)
            return 0;

        int val = pow(num, x);
        if (val > n)
            return 0;

        if (t[n][num] != -1)
            return t[n][num];

        return t[n][num] =
                   (func(n - val, num + 1, x) + func(n, num + 1, x)) % M;
    }
    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t));
        return func(n, 1, x);
    }
};
