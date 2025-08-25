class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        vector<int> vec;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[0].size(); j++)
                mp[i + j].push_back(mat[i][j]);

        bool neg = true;
        for (auto& m : mp) {
            if (neg)
                reverse(m.second.begin(), m.second.end());
            for (int& num : m.second)
                vec.push_back(num);
            neg = !neg;
        }
        return vec;
    }
};
