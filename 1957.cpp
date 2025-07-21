class Solution {
public:
    string makeFancyString(string s) {
        string fancy = "";
        fancy.push_back(s[0]);
        int cnt = 1;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i - 1] == s[i]) {
                cnt++;
                if (cnt >= 3)
                    continue;
            } else
                cnt = 1;
            fancy.push_back(s[i]);
        }
        return fancy;
    }
};
