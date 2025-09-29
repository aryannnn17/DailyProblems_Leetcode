class Solution {
public:
    int t[50][50];
    int solve(vector<int>& values, int i, int j) {
        if (j - i < 2)
            return 0;
        if (t[i][j] != -1)
            return t[i][j];
        int ans = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            int weight = solve(values, i, k) +
                         values[i] * values[k] * values[j] +
                         solve(values, k, j);
            ans = min(ans, weight);
        }
        return t[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        memset(t, -1, sizeof(t));
        return solve(values, 0, values.size() - 1);
    }
};
