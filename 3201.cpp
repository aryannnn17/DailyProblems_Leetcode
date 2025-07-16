class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd = 0, even = 0, alt = 1;
        for (int& i : nums) {
            if (i % 2 == 0)
                even++;
            else
                odd++;
        }
        int curr = nums[0] % 2;
        for (int i = 1; i < nums.size(); ++i) {
            int next = nums[i] % 2;
            if (curr != next) {
                curr = next;
                alt++;
            }
        }
        return max({odd, even, alt});
    }
};
