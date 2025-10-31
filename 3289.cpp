class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> dup;
        for (int i : nums) {
            mp[i]++;
            if (mp[i] == 2)
                dup.push_back(i);
        }
        return dup;
    }
};
