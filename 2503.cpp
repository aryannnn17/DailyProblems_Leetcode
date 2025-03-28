class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> result(queries.size(), 0);
        vector<pair<int, int>> sorted;
        for (int i = 0; i < queries.size(); i++) {
            sorted.push_back({queries[i], i});
        }

        sort(begin(sorted), end(sorted));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int points = 0;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        for (int i = 0; i < queries.size(); i++) {
            int queryValue = sorted[i].first;
            int idx = sorted[i].second;
            while (!pq.empty() && pq.top()[0] < queryValue) {
                int i = pq.top()[1];
                int j = pq.top()[2];
                pq.pop();
                points++;

                for (auto& dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];
                    if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n &&
                        !visited[i_][j_]) {
                        pq.push({grid[i_][j_], i_, j_});
                        visited[i_][j_] = true;
                    }
                }
            }
            result[idx] = points;
        }
        return result;
    }
};

// ------- BFS -------- (TLE)
// class Solution {
// public:
//     vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//     int dfs(vector<vector<int>>& grid, int i, int j, int val,
//             vector<vector<bool>>& visited, int m, int n) {
//         if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] ||
//             grid[i][j] >= val) {
//             return 0;
//         }
//         visited[i][j] = true;
//         int points = 1;
//         for (auto& dir : directions) {
//             int i_ = i + dir[0];
//             int j_ = j + dir[1];
//             points += dfs(grid, i_, j_, val, visited, m, n);
//         }
//         return points;
//     }

//     vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {

//         vector<int> ans(queries.size(), 0);
//         for (int i = 0; i < queries.size(); i++) {
//             vector<vector<bool>> visited(grid.size(),
//                                          vector<bool>(grid[0].size(),
//                                          false));
//             ans[i] = dfs(grid, 0, 0, queries[i], visited, grid.size(),
//                             grid[0].size());
//         }

//         return ans;
//     }
// };
