class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<int> vec(32, -1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            int end = i;
            for (int j = 0; j < 32; j++) {
                if (!(nums[i] & (1 << j))) {
                    if (vec[j] != -1)
                        end = max(end, vec[j]);
                } else
                    vec[j] = i;
            }
            ans[i] = end - i + 1;
        }
        return ans;
    }
};
