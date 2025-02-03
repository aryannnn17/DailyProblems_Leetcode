class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int decLen = 1, incLen = 1, len1 = 1, len2 = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1])
                decLen++;
            else
                decLen = 1;
            len1 = max(decLen, len1);
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] < nums[i + 1])
                incLen++;
            else
                incLen = 1;
            len2 = max(incLen, len2);
        }
        return max(len1, len2);
    }
};
