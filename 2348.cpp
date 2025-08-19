class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long ans = 0;
        long cnt = 0;
        for (int i : nums) {
            if (i == 0) {
                cnt++;
                ans += cnt;
            } else
                cnt = 0;
        }
        return ans;
    }
};
