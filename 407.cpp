class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<p, vector<p>, greater<>> boundaryCells;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int r = 0; r < m; ++r)
            for (int c : {0, n - 1}) {
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }
        for (int c = 0; c < n; ++c)
            for (int r : {0, m - 1}) {
                boundaryCells.push({heightMap[r][c], {r, c}});
                visited[r][c] = true;
            }

        int ans = 0;
        while (!boundaryCells.empty()) {
            auto [height, cell] = boundaryCells.top();
            boundaryCells.pop();

            for (vector<int>& dir : directions) {
                int i = cell.first + dir[0];
                int j = cell.second + dir[1];
                if (i >= 0 && i < m && j >= 0 && j < n && !visited[i][j]) {
                    ans += max(0, height - heightMap[i][j]);
                    boundaryCells.push({max(height, heightMap[i][j]), {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        return ans;
    }
};
