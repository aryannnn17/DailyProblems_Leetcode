class Solution {
    int MOD = 1e9 + 7;
    int mem[1000 + 2][1023];
    int countWays(int& m, int& n, int r, int c, int curr, int prev) {
        if (c == n)
            return 1;
        if (r == m)
            return countWays(m, n, 0, c + 1, 0, curr);
        if (r == 0 and mem[c][prev] != -1)
            return mem[c][prev];

        int up = 0;
        if (r > 0)
            up = curr & 3;

        int left = (prev >> ((m - r - 1) * 2)) & 3;
        int ways = 0;
        for (int i = 1; i <= 3; ++i)
            if (i != up and i != left)
                ways = (ways + countWays(m, n, r + 1, c, (curr << 2) + i, prev)) % MOD;

        if (r == 0)
            mem[c][prev] = ways;
        return ways;
    }

public:
    int colorTheGrid(int m, int n) {
        memset(mem, -1, sizeof(mem));
        return countWays(m, n, 0, 0, 0, 0);
    }
};
