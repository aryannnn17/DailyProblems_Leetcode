class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        while (n--) {
            int val = nums[0];
            for (int i = 0; i < nums.size() - 1; ++i)
                nums[i] = nums[i + 1];

            nums[nums.size() - 1] = val;
            if (temp == nums)
                return true;
        }
        return false;
    }
};
