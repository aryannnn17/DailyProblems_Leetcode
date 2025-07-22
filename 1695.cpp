class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int l = 0, sum = 0;
        unordered_map<int, int> freq;
        for (int r = 0; r < nums.size(); ++r) {
            while (freq[nums[r]] > 0) {
                sum -= nums[l];
                freq[nums[l]]--;
                l++;
            }
            sum += nums[r];
            freq[nums[r]]++;
            ans = max(ans, sum);
        }
        return ans;
    }
};
