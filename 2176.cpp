class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int cnt = 0;
        while (i < nums.size() - 1) {
            int j = i + 1;
            while (j < nums.size()) {
                if (nums[i] == nums[j] && ((i * j) % k == 0)) {
                    cnt++;
                }
                j++;
            }
            i++;
        }
        return cnt;
    }
};
