class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        vector<vector<int>> v(n, vector<int>(n, 0));

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += fruits[i][i];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i < j && i + j < n - 1)
                    v[i][j] = 0;
                else if (i > j && i + j < n - 1)
                    v[i][j] = 0;
                else
                    v[i][j] = fruits[i][j];
            }
        }

        for (int i = 1; i < n; i++)
            for (int j = i + 1; j < n; j++)
                v[i][j] += max({v[i - 1][j - 1], v[i - 1][j],
                                (j + 1 < n) ? v[i - 1][j + 1] : 0});

        for (int i = 1; i < n; i++)
            for (int j = i + 1; j < n; j++)
                v[j][i] += max({v[j - 1][i - 1], v[j][i - 1],
                                (j + 1 < n) ? v[j + 1][i - 1] : 0});

        return ans + v[n - 2][n - 1] + v[n - 1][n - 2];
    }
};
