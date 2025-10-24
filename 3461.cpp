class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() != 2) {
            string t = "";
            for (int i = 0; i < s.length() - 1; ++i)
                t.push_back(((s[i] + s[i + 1] - 96) % 10) + 48);
            s = t;
        }
        return s[0] == s[1] ? 1 : 0;
    }
};
