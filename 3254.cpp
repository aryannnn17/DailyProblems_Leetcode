class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        if (k == 1)
            return nums;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            for (int j = i; j < i + k - 1; j++) {
                if (nums.at(j) + 1 != nums.at(j + 1)) {
                    ans.push_back(-1);
                    break;
                } else if ((j + 1) == (i + k - 1)) {
                    ans.push_back(nums.at(j + 1));
                }
            }
        }
        return ans;
    }
};
