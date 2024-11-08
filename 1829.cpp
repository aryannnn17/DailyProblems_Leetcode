class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> preXOR = nums;
        int ans = 0, n = pow(2, maximumBit) - 1;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums.at(i);
            preXOR.at(nums.size() - i - 1) = ans ^ n;
        }
        return preXOR;
    }
};
