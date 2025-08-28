class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                mp[i - j].push_back(grid[i][j]);

        for (auto& m : mp) {
            if (m.first >= 0)
                sort(begin(m.second), end(m.second));
            else
                sort(rbegin(m.second), rend(m.second));
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                grid[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }
        return grid;
    }
};
