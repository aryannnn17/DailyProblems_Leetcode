class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            int min_num = *min_element(nums.begin(), nums.end());
            auto idx = find(nums.begin(), nums.end(), min_num);
            nums.at(distance(nums.begin(), idx)) *= multiplier;
        }
        return nums;
    }
};
