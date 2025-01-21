class Solution {
#define ll long long
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll row1 = accumulate(begin(grid[0]), end(grid[0]), 0LL), row2 = 0,R2 = LONG_LONG_MAX;
        for (int i = 0; i < grid[0].size(); i++) {
            row1 -= grid[0][i];
            ll path = max(row1, row2);
            R2 = min(R2, path);
            row2 += grid[1][i];
        }
        return R2;
    }
};
