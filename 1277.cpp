class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return 0;
       
        vector<vector<int>> t(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ans = 0;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i == 0 || j == 0)
                    t[i][j] = matrix[i][j];
                else if (matrix[i][j] == 1)
                    t[i][j] =
                        1 + min({t[i - 1][j], t[i][j - 1], t[i - 1][j - 1]});
                ans += t[i][j];
            }
        }

        return ans;
    }
};
