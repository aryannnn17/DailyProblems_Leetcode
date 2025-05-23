class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long sum = 0;
        int cnt = 0;
        int m = INT_MAX;
        for (long i : nums) {
            if ((i ^ k) > i) {
                cnt++;
                sum += (i ^ k);
            } else
                sum += i;

            m = min((long)m, abs(i - (i ^ k)));
        }
        if (cnt % 2 == 0)
            return sum;
        return sum - m;
    }
};
