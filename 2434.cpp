class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> cnt(n);
        cnt[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--)
            cnt[i] = min(s[i], cnt[i + 1]);

        string t = "";
        string p = "";
        int i = 0;
        while (i < n) {
            t.push_back(s[i]);
            char minChar = (i + 1 < n) ? cnt[i + 1] : s[i];
            while (!t.empty() && t.back() <= minChar) {
                p += t.back();
                t.pop_back();
            }
            i++;
        }

        while (!t.empty()) {
            p += t.back();
            t.pop_back();
        }
        return p;
    }
};
