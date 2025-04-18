class Solution {
public:
    string countAndSay(int n) {
        int i = 2;
        string s = "11";
        if (n == 1)
            return "1";
        while (i < n) {
            string t = "";
            int cnt = 1;
            for (int j = 0; j < s.length(); ++j) {
                if (j + 1 < s.length() && s[j] == s[j + 1]) {
                    cnt++;
                } else {
                    t += to_string(cnt);
                    t += s[j];
                    cnt = 1;
                }
            }
            s = t;
            i++;
        }
        return s;
    }
};c
