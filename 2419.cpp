class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxAND = *max_element(nums.begin(), nums.end());
        int ans = 1;
        int len = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == maxAND && nums[i] == nums[i + 1])
                ans++;
            else
                ans = 1;
            len = max(ans, len);
        }
        return len;
    }
};
