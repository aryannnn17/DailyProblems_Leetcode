class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> freq((grid.size()*grid.size())+1, 0);
        int a;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j) {
                if (freq[grid[i][j]] == 1)
                    a = grid[i][j];
                freq[grid[i][j]]++;
            }

        for (int i = 1; i < freq.size(); ++i)
            if (freq[i] == 0)
                return {a, i};

        return {a, -1};
    }
};
