class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> freq(101, 0);
        int idx = -1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            freq[nums[i]]++;
            if (freq[nums[i]] > 1) {
                idx = i;
                return ceil(double(idx + 1) / 3);
            }
        }
        return 0;
    }
};
