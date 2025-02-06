class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
            for (int j = i + 1; j < nums.size(); ++j) {
                mp[nums[i] * nums[j]]++;
                if (mp[nums[i] * nums[j]] > 1)
                    count += (mp[nums[i] * nums[j]] - 1);
            }
        return count*8;
    }
};
