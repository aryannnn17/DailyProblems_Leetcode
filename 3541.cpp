class Solution {
public:
    int maxFreqSum(string s) {
        sort(s.begin(), s.end());
        int cVow = 0, cCon = 0, cnt = 0;
        char curr = s[0];
        for (char& c : s) {
            if (curr != c)
                cnt = 0;
            curr = c;
            cnt++;
            if (c == 'a' || c == 'o' || c == 'i' || c == 'e' || c == 'u')
                cVow = max(cnt, cVow);
            else
                cCon = max(cnt, cCon);
        }
        return cCon + cVow;
    }
};
