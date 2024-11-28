class Solution {
#define pip pair<int, pair<int, int>>
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<pip, vector<pip>, greater<pip>> min;
        min.push({0, {0, 0}});
        visited[0][0] = true;

        while (!min.empty()) {
            pip curr = min.top();
            min.pop();

            int x = curr.second.first;
            int y = curr.second.second;
            int cost = curr.first;

            if (x == m - 1 and y == n - 1)
                return cost;

            for (int i = 0; i < 4; ++i) {
                int X = x + dir[i];
                int Y = y + dir[i + 1];
                if (X >= 0 and X < m and Y >= 0 and Y < n and !visited[X][Y]) {
                    visited[X][Y] = true;
                    if (grid[X][Y] == 1)
                        min.push({cost + 1, {X, Y}});
                    else
                        min.push({cost, {X, Y}});
                }
            }
        }
        return 0;
    }
};
