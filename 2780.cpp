class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int maj = -1;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                maj = nums[i];
                cnt = 1;
            } else if (nums[i] == maj)
                cnt++;
            else
                cnt--;
        }
        int majcnt = 0;
        for (int& i : nums)
            if (i == maj)
                majcnt++;
        cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maj)
                cnt++;

            int remainingcnt = majcnt - cnt;
            int n1 = i + 1;
            int n2 = nums.size() - i - 1;
            if (cnt * 2 > n1 && remainingcnt * 2 > n2) {
                return i;
            }
        }
        return -1;
    }
};
