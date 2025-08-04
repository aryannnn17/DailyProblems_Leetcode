class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        vector<int> prefixSum(n);
        vector<int> indices(n);

        for (int i = 0; i < n; i++) {
            indices[i] = fruits[i][0];
            prefixSum[i] = fruits[i][1] + (i > 0 ? prefixSum[i - 1] : 0);
        }

        int maxFrutis = 0;
        for (int d = 0; d <= k / 2; d++) {
            int l = lower_bound(indices.begin(), indices.end(), startPos - d) -
                    indices.begin();
            int r = upper_bound(indices.begin(), indices.end(),
                                startPos + (k - 2 * d)) -
                    indices.begin() - 1;

            if (l <= r) {
                int total = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
                maxFrutis = max(maxFrutis, total);
            }

            l = lower_bound(indices.begin(), indices.end(), startPos - (k - 2 * d)) -
                indices.begin();
            r = upper_bound(indices.begin(), indices.end(), startPos + d) -
                indices.begin() - 1;

            if (l <= r) {
                int total = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
                maxFrutis = max(maxFrutis, total);
            }
        }

        return maxFrutis;
    }
};
