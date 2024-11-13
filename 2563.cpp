class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;

        //-----RUNTIME ERROR FOR LARGER INPUT-----//
        // for (int i = 0; i < nums.size() - 1; i++)
        //     for (int j = i + 1; j < nums.size(); j++) 
        //         if (lower <= nums.at(i) + nums.at(j) and nums.at(i) + nums.at(j) <= upper)
        //             count++;
            
        for(int i = 0; i < nums.size(); i++) {
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto high = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            count += high - low;
        }
        return count;
    }
};
