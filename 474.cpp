class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));
        for (string s : strs) {
            int ones = 0;
            int zeros = 0;
            for (char c : s) {
                if (c == '1')
                    ones++;
                else
                    zeros++;
            }
            for (int z = m; z >= zeros; z--)
                for (int o = n; o >= ones; o--)
                    t[z][o] = max(t[z][o], t[z - zeros][o - ones] + 1);
        }

        return t[m][n];
    }
};
