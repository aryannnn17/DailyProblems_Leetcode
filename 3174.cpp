class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >= '0' && s[i] <= '9')
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};
