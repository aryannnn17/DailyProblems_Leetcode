class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> mp(501, 0);
        for (int i : nums)
            mp[i]++;

        for (auto i : mp)
            if (i % 2 == 1)
                return false;
        return true;
    }
};
