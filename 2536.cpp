class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));

        for (auto& q : queries) {
            for (int i = q[0]; i <= q[2]; i++) {
                diff[i][q[1]] += 1;
                if (q[3] + 1 < n)
                    diff[i][q[3] + 1] -= 1;
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 1; j < n; j++)
                diff[i][j] += diff[i][j - 1];

        return diff;
    }
};
