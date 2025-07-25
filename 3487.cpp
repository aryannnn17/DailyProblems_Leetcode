class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        for (int i : nums)
            if (i > 0)
                s.insert(i);
        int sum = 0;
        for (int i : s)
            sum += i;
        sort(nums.begin(), nums.end());
        return s.empty() ? nums[nums.size() - 1] : sum;
    }
};
