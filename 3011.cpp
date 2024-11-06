class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int curr = nums[0], numMin = nums[0], numMax = nums[0], prevMax = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (__builtin_popcount(curr) == __builtin_popcount(nums[i])) {
                numMax = max(numMax, nums[i]);
                numMin = min(numMin, nums[i]);
            } else {
                if (prevMax > numMin) {
                    return false;
                }
                curr = nums[i];
                prevMax = numMax;
                numMax = nums[i];
                numMin = nums[i];
            }
        }
        return prevMax <= numMin;
    }
};
