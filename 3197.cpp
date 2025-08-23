class Solution {
public:
    vector<vector<int>> rotateClockWise(vector<vector<int>>& grid) {
        vector<vector<int>> vec(grid[0].size(), vector<int>(grid.size()));
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                vec[j][grid.size() - i - 1] = grid[i][j];
        return vec;
    }

    int minimumArea(int startRow, int endRow, int startCol, int endCol,
                    vector<vector<int>>& grid) {
        int minRow = grid.size();
        int maxRow = -1;
        int minCol = grid[0].size();
        int maxCol = -1;
        for (int i = startRow; i < endRow; i++) {
            for (int j = startCol; j < endCol; j++) {
                if (grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        if (maxRow == -1) return 0;
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }

    int utility(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        for (int r = 1; r < grid.size(); r++) {
            for (int c = 1; c < grid[0].size(); c++) {
                int t = minimumArea(0, r, 0, grid[0].size(), grid);
                int bLeft = minimumArea(r, grid.size(), 0, c, grid);
                int bRight = minimumArea(r, grid.size(), c, grid[0].size(), grid);
                ans = min(ans, t + bLeft + bRight);

                int tLeft = minimumArea(0, r, 0, c, grid);
                int tRight = minimumArea(0, r, c, grid[0].size(), grid);
                int b = minimumArea(r, grid.size(), 0, grid[0].size(), grid);
                ans = min(ans, tLeft + tRight + b);
            }
        }
        for (int s1 = 1; s1 < grid.size(); s1++) {
            for (int s2 = s1 + 1; s2 < grid.size(); s2++) {
                int t = minimumArea(0, s1, 0, grid[0].size(), grid);
                int m = minimumArea(s1, s2, 0, grid[0].size(), grid);
                int b = minimumArea(s2, grid.size(), 0, grid[0].size(), grid);
                ans = min(ans, t + m + b);
            }
        }
        return ans;
    }

    int minimumSum(vector<vector<int>>& grid) {
        int ans = utility(grid);
        vector<vector<int>> vec = rotateClockWise(grid);
        ans = min(ans, utility(vec));
        return ans;
    }
};
