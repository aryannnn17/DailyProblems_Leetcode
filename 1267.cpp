class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> RowServer(m, -1), colServer(n, 0);
        int res = 0;

        for (int row = 0; row < m; row++) {
            int count = 0;
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    count += 1;
                    colServer[col]++;
                    RowServer[row] = col;
                }
            }

            if (count > 1) {
                res += count;
                RowServer[row] = -1;
            }
        }

        for (int row = 0; row < m; row++) {
            if (RowServer[row] != -1) {
                int col = RowServer[row];
                if (colServer[col] > 1) {
                    res += 1;
                }
            }
        }

        return res;
    }
};
