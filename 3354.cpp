class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curr = 0;
        int S = accumulate(begin(nums), end(nums), 0);
        for (int i = 0; i < n; i++) {
            curr += nums[i];
            int l = curr;
            int r = S - l;
            if (nums[i] != 0)
                continue;

            if (l == r)
                ans += 2;

            if (abs(l - r) == 1)
                ans += 1;
        }

        return ans;
    }
};
