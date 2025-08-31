class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < board.size(); ++i) {
            vector<char> row, cols;
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] != '.' &&
                    find(row.begin(), row.end(), board[i][j]) != row.end())
                    return false;
                else if (board[i][j] != '.')
                    row.push_back(board[i][j]);

                if (board[j][i] != '.' &&
                    find(cols.begin(), cols.end(), board[j][i]) != cols.end())
                    return false;
                else if (board[j][i] != '.')
                    cols.push_back(board[j][i]);

                if (i % 3 == 0 && j % 3 == 0) {
                    vector<char> box;
                    for (int m = 0; m < 3; ++m) {
                        for (int n = 0; n < 3; ++n) {
                            if (board[i + m][j + n] != '.' &&
                                find(box.begin(), box.end(),
                                     board[i + m][j + n]) != box.end())
                                return false;
                            box.push_back(board[i + m][j + n]);
                        }
                    }
                }
            }
        }
        return true;
    }
};
