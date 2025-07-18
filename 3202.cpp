class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(nums.size(), 1));
        int maxSub = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                int m = (nums[j] + nums[i]) % k;
                dp[m][i] = max(dp[m][i], 1 + dp[m][j]);
                maxSub = max(maxSub, dp[m][i]);
            }
        }
        return maxSub;
    }
};
