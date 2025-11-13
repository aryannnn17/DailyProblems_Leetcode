class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int cnt1 = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] == 1)
                cnt1++;

        if (cnt1 > 0)
            return n - cnt1;

        int opr = INT_MAX;
        for (int i = 0; i < n; i++) {
            int GCD = nums[i];
            for (int j = i + 1; j < n; j++) {
                GCD = gcd(GCD, nums[j]);
                if (GCD == 1) {
                    opr = min(opr, j - i);
                    break;
                }
            }
        }

        if (opr == INT_MAX) {
            return -1;
        }
        return opr + (n - 1);
    }
};
