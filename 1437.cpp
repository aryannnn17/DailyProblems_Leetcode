class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (idx != -1 && i - idx <= k)
                    return false;
                idx = i;
            }
        }
        return true;
    }
};
