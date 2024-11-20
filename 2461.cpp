class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0, currentSum = 0;
        unordered_map<int, int> freq;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;
            currentSum += nums[right];
            while (freq[nums[right]] > 1 || (right - left + 1) > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                currentSum -= nums[left];
                left++;
            }
            if ((right - left + 1) == k && freq.size() == k) {
                maxSum = max(maxSum, currentSum);
            }
        }
        return maxSum;
    }
};
