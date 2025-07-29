class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int num = 0;
        for (int i : nums)
            num |= i;
        int cnt = 0;
        int n = pow(2, nums.size());
        for (int m = 1; m < n; ++m) {
            int curr = 0;
            for (int i = 0; i < nums.size(); ++i)
                if (m & (1 << i))
                    curr |= nums[i];

            if (curr == num)
                ++cnt;
        }
        return cnt;
    }
};
