class Solution {
public:
    vector<vector<int>> direc{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    using P = pair<int, pair<int, int>>;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n, INT_MAX));
        
        priority_queue<P, vector<P>, greater<P>> pq; 
        ans[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            int currT = pq.top().first;
            auto c = pq.top().second;
            int i = c.first;
            int j = c.second;
            pq.pop();

            if (i == n - 1 && j == n - 1)
                return currT;

            if (currT > ans[i][j]) continue;

            for (auto& dir : direc) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n) {
                    int nextT = max(currT, grid[i_][j_]);

                    if (nextT < ans[i_][j_]) {
                        ans[i_][j_] = nextT;
                        pq.push({nextT, {i_, j_}});
                    }
                }
            }
        }

        return -1; 
    }
};
