class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {

        int curr = 1;
        int prev = 0;
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                curr++;
            } else {
                prev = curr;
                curr = 1;
            }

            ans = max(ans, curr / 2);
            ans = max(ans, min(prev, curr));
        }

        return ans;
    }
};
