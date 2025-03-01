class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
                i++;
            }
        }
        int countZero = 0;
        for (int& i : nums)
            if (i == 0)
                countZero++;
            else
                res.push_back(i);
        while (countZero--)
            res.push_back(0);
        return res;
    }
};
