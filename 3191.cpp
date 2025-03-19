class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i = 0, cnt = 0;
        while (i < nums.size() - 2) {
            if (nums[i] == 0) {
                nums[i] = !nums[i];
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
                cnt++;
            }
            i++;
        }
        if (nums[nums.size() - 2] == 1 && nums[nums.size() - 1] == 1)
            return cnt;
        return -1;
    }
};
