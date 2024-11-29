class Solution {
#define pip pair<int, pair<int, int>>
public:
    int minimumTime(vector<vector<int>>& grid) {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][1] > 1 + grid[0][0] and grid[1][0] > 1 + grid[0][0])
            return -1;
        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<pip, vector<pip>, greater<pip>> minheap;
        minheap.push({0, {0, 0}});
        visited[0][0] = true;
        while (!minheap.empty()) {
            pip curr = minheap.top();
            minheap.pop();

            int time = curr.first, x = curr.second.first,
                y = curr.second.second;
            if (x == m - 1 and y == n - 1)
                return time;
            for (int i = 0; i < 4; ++i) {
                int X = x + dir[i];
                int Y = y + dir[i + 1];
                if (X >= 0 and X < m and Y >= 0 and Y < n and !visited[X][Y]) {
                    visited[X][Y] = true;
                    int T = 1 + time;
                    if (grid[X][Y] > T)
                        T = (grid[X][Y] - time) & 1 ? grid[X][Y]
                                                    : grid[X][Y] + 1;
                    minheap.push({T, {X, Y}});
                }
            }
        }
        return -1;
    }
};
