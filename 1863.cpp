class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = nums[i];
            for (int j = i + 1; j < nums.size(); ++j) {
                sum = sum ^ nums[j];
                total += sum;
            }
        }
        return ans;
    }
};
