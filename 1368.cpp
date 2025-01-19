// class Solution {
// public:
//     vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//     int m, n;
//     int dfs(int i, int j, vector<vector<int>>& grid,
//             vector<vector<bool>>& visited, int cost) {
//         if (i == m - 1 && j == n - 1) 
//             return cost;
//         
//         visited[i][j] = true;
//         int minCost = INT_MAX;
//         for (int k = 0; k <= 3; k++) {
//             int a = i + dir[k][0];
//             int b = j + dir[k][1];
//             if (a >= 0 && a < m && b >= 0 && b < n && !visited[a][b]) {
//                 int nextCost = cost + ((grid[i][j] - 1 != k) ? 1 : 0);
//                 minCost = min(minCost, dfs(a, b, grid, visited, nextCost));
//             }
//         }
//         visited[i][j] = false;
//         return minCost;
//     }

//     int minCost(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         return dfs(0, 0, grid, visited, 0);
//     }
// };


// -----< Using Dijkstra's Algorithm >-------
class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        result[0][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currCost = curr[0], i = curr[1], j = curr[2];
            if (result[i][j] < currCost)
                continue;

            for (int k = 0; k <= 3; k++) {
                int a = i + dir[k][0], b = j + dir[k][1];

                if (a >= 0 && b >= 0 && a < m && b < n) {
                    int gridDir = grid[i][j];
                    int dirCost = ((gridDir - 1 != k) ? 1 : 0);

                    int cost = currCost + dirCost;
                    if (cost < result[a][b]) {
                        result[a][b] = cost;
                        pq.push({cost, a, b});
                    }
                }
            }
        }
        return result[m - 1][n - 1];
    }
};
