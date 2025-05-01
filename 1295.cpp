class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            int cnt = 0;
            while (i) {
                cnt++;
                i = i / 10;
            }
            if (cnt % 2 == 0)
                ans++;
        }
        return ans;
    }
};
