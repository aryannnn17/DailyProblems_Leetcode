class Solution {
public:
    vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int m, n;
    int t[501][501][4][2];

    int solve(int i, int j, int d, bool turn, int val,
              vector<vector<int>>& grid) {
        int i_ = i + dir[d][0];
        int j_ = j + dir[d][1];

        if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] != val)
            return 0;

        if (t[i_][j_][d][turn] != -1)
            return t[i_][j_][d][turn];

        int ans = 0;
        int kmove = 1 + solve(i_, j_, d, turn, val == 2 ? 0 : 2, grid);
        ans = max(ans, kmove);

        if (turn == true) {
            int tmove =
                max(kmove, 1 + solve(i_, j_, (d + 1) % 4, false,
                                          val == 2 ? 0 : 2, grid));
            ans = max(ans, tmove);
        }

        return t[i_][j_][d][turn] = ans;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t, -1, sizeof(t));
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    for (int d = 0; d <= 3; d++)
                        ans = max(ans, 1 + solve(i, j, d, true, 2, grid));

        return ans;
    }
};
