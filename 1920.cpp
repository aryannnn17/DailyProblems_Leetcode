class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for (int i : nums)
            ans.push_back(nums[i]);
        return ans;
    }
};
