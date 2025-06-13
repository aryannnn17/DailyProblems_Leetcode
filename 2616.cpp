class Solution {
public:
    int n;
    bool func(vector<int>& nums, int mid, int p) {
        int i = 0;
        int pairs = 0;
        while (i < n - 1) {
            if (nums[i + 1] - nums[i] <= mid) {
                pairs++;
                i += 2;
            } else
                i++;
        }
        return pairs >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums[n - 1] - nums[0];
        int ans = INT32_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (func(nums, mid, p)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};
