class Solution {
public:
    vector<int> arr;
    int res;
    int ans = 0;
    int n;
    void rec(int level, int sum) {
        if (level == n) {
            if (sum == res)
                ans++;
            return;
        }
        rec(level + 1, sum + arr[level]);
        rec(level + 1, sum - arr[level]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        arr = nums;
        n = nums.size();
        res = target;
        rec(0, 0);
        return ans;
    }
};
