class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int st = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] - st > k) {
                cnt++;
                st = nums[i];
            }
        }
        return cnt;
    }
};
