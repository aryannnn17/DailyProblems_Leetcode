class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (ans.size() == k) {
                auto minNum = min_element(ans.begin(), ans.end());
                if (nums[i] > *minNum) {
                    ans.erase(minNum);
                    ans.push_back(nums[i]);
                }
            } else
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
