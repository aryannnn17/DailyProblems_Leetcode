class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int pre = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (pre < nums[i] - k) {
                pre = nums[i] - k;
                cnt++;
            } else if (pre < nums[i] + k) {
                pre += 1;
                cnt++;
            }
        }
        return cnt;
    }
};
