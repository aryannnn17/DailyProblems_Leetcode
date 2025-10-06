class Solution {
public:
    vector<vector<int>> direc{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void DFS(vector<vector<int>>& matrix, int i, int j, int prev,
             vector<vector<bool>>& visited) {
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())
            return;

        if (matrix[i][j] < prev || visited[i][j])
            return;
        visited[i][j] = true;
        for (auto dir : direc) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            DFS(matrix, ni, nj, matrix[i][j], visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0)
            return {};
        int col = matrix[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(row, vector<bool>(col));
        vector<vector<bool>> atlantic(row, vector<bool>(col));

        for (int j = 0; j < col; j++) {
            DFS(matrix, 0, j, INT_MIN, pacific);
            DFS(matrix, row - 1, j, INT_MIN, atlantic);
        }

        for (int i = 0; i < row; i++) {
            DFS(matrix, i, 0, INT_MIN, pacific);
            DFS(matrix, i, col - 1, INT_MIN, atlantic);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};
