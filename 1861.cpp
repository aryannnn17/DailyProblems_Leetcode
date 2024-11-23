class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // int n = box.size();
        // int m = box[0].size();
        for (int i = 0; i < box.size(); ++i) {
            int empty = box[0].size() - 1;
            for (int j = box[0].size() - 1; j >= 0; --j) {
                if (box[i][j] == '#') {
                    swap(box[i][j], box[i][empty--]);
                } else if (box[i][j] == '*') {
                    empty = j - 1;
                }
            }
        }
        vector<vector<char>> res(box[0].size(), vector<char>(box.size()));
        for (int i = 0; i < box.size(); ++i) {
            for (int j = 0; j < box[0].size(); ++j) {
                res[j][box.size() - i - 1] = box[i][j];
            }
        }
        return res;
    }
};
