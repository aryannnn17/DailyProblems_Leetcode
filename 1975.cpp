class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int val = INT_MAX, num = 0;
        long long sum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += abs(matrix[i][j]);
                val = min(val, abs(matrix[i][j]));

                if (matrix[i][j] < 0)
                    num++;
            }
        }
        if (num % 2 == 0)
            return sum;
        long long ans = sum - 2 * val;
        return ans;
    }
};
