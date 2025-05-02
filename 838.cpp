class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";
        string ans = "";
        for (int i = 0, j = 1; j < s.length(); j++) {
            if (s[j] == '.')
                continue;
            int mid = j - i - 1;
            if (i > 0)
                ans.push_back(s[i]);

            if (s[i] == s[j])
                ans += string(mid, s[i]);
            else if (s[i] == 'L' && s[j] == 'R')
                ans += string(mid, '.');
            else
                ans += string(mid / 2, 'R') +
                       string(mid % 2, '.') +
                       string(mid / 2, 'L');
            i = j;
        }
        return ans;
    }
};
