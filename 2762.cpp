class Solution {
#define ll long long
#define pii pair<int, int>
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size(), left = 0, range_min = INT_MAX, range_max = INT_MIN;
        ll count = 0, win_size;
        int right;
        for (right = 0; right < n; ++right) {
            range_min = min(range_min, nums[right]);
            range_max = max(range_max, nums[right]);
            if (range_max - range_min > 2) {
                win_size = right - left;
                count += (win_size * (win_size + 1)) / 2;
                left = right;
                range_min = nums[right];
                range_max = nums[right];
                while (abs(nums[right] - nums[left - 1]) <= 2) {
                    left--;
                    range_min = min(range_min, nums[left]);
                    range_max = max(range_max, nums[left]);
                }

                if (left < right) {
                    win_size = right - left;
                    count -= (win_size * (win_size + 1)) / 2;
                }
            }
        }
        win_size = right - left;
        count += (win_size * (win_size + 1)) / 2;
        return count;
    }
};
