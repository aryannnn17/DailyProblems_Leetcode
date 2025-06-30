class Solution {
    int M = 1e9 + 7;

public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        vector<int> power(nums.size());
        power[0] = 1;
        for (int i = 1; i < nums.size(); i++)
            power[i] = (power[i - 1] * 2) % M;

        int ans = 0;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                int diff = r - l;
                ans = (ans % M + power[diff]) % M;
                l++;
            } else 
                r--;
            
        }
        return ans;
    }
};
