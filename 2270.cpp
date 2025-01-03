class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int splits = 0;
        long long sum = 0, leftSum = 0;
        for (auto& i : nums)
            sum += i;
        for (int i = 0; i < nums.size() - 1; ++i) {
            leftSum += nums[i];
            sum -= nums[i];
            if (leftSum >= sum)
                splits++;
        }
        return splits;
    }
};
