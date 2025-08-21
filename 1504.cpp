class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        for (int r = 0; r < mat.size(); r++)
            for (int c = mat[0].size() - 2; c >= 0; c--)
                if (mat[r][c])
                    mat[r][c] += mat[r][c + 1];

        int cnt = 0;
        for (int r = 0; r < mat.size(); r++) {
            for (int c = 0; c < mat[0].size(); c++) {
                int width = mat[r][c];

                for (int d = r; d < mat.size(); d++) {
                    if (mat[d][c] == 0)
                        break;
                    width = min(width, mat[d][c]);
                    cnt += width;
                }
            }
        }
        return cnt;
    }
};
