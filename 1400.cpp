class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k)
            return false;
        int odd = 0;
        unordered_map<char, int> mp;
        for (auto i : s)
            mp[i]++;
        for (auto i : mp) {
            if (i.second % 2 == 1)
                odd++;
            if (odd > k)
                return false;
        }
        return true;
    }
};
