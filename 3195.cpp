class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minl = grid.size(), minw = grid[0].size();
        int maxl = -1, maxw = -1;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == 1) {
                    maxl = max(maxl, r);
                    maxw = max(maxw, c);
                    minl = min(minl, r);
                    minw = min(minw, c);
                }
            }
        }
        return (maxl - minl + 1) * (maxw - minw + 1);
    }
};
