class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff = -1;
        int minNum = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            minNum = min(minNum, nums[i]);
            diff = max(diff, nums[i] - minNum);
        }
        return (diff == 0) ? -1 : diff;
    }
};
