class Solution {
    vector<int> dir = {-1, 0, 1, 0, -1};
    void step(int x, int y, int direction, vector<vector<int>>& grid) {
        if (x < 0 or x >= grid.size() || y < 0 || y >= grid[0].size() ||
            grid[x][y] == 2 || grid[x][y] == 3)
            return;
        grid[x][y] = 1;
        if (direction == 0)
            step(x - 1, y, direction, grid);
        else if (direction == 1)
            step(x, y + 1, direction, grid);
        else if (direction == 2)
            step(x + 1, y, direction, grid);
        else if (direction == 3)
            step(x, y - 1, direction, grid);
    }

public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto g : guards)
            grid[g[0]][g[1]] = 2;

        for (auto w : walls)
            grid[w[0]][w[1]] = 3;

        for (auto g : guards) {
            for (int i = 0; i < 4; ++i) {
                int x = g[0] + dir[i];
                int y = g[1] + dir[i + 1];
                step(x, y, i, grid);
            }
        }
        int unguarded = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 0)
                    unguarded += 1;
        return unguarded;
    }
};
