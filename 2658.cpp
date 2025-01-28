class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int BFS(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        int fishCount = grid[i][j];
        grid[i][j] = 0;
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for (auto& dir : directions) {
                int i_ = dir[0] + i;
                int j_ = dir[1] + j;
                if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n &&
                    grid[i_][j_] > 0) {
                    q.push({i_, j_});
                    fishCount += grid[i_][j_];
                    grid[i_][j_] = 0;
                }
            }
        }

        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxFish = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] > 0)
                    maxFish = max(maxFish, BFS(i, j, grid));

        return maxFish;
    }
};
