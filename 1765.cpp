class Solution {
#define P pair<int, int>
public:
    vector<vector<int>> dir{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<P> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                P curr = q.front();
                q.pop();
                for (auto& d : dir) {
                    int a = curr.first + d[0];
                    int b = curr.second + d[1];
                    if (a >= 0 && a < m && b >= 0 && b < n &&
                        height[a][b] == -1) {
                        height[a][b] =
                            height[curr.first][curr.second] + 1;
                        q.push({a, b});
                    }
                }
            }
        }
        return height;
    }
};
