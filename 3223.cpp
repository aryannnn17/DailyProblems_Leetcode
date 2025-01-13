class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        int count = s.length();
        for (auto& i : s) {
            mp[i]++;
            if (mp[i] >= 3) {
                count -= 2;
                mp[i] -= 2;
            }
        }
        return count;
    }
};
