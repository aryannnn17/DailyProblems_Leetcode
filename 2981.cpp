class Solution {
    int& getMin(int& a, int& b, int& c) {
        if (a <= b and a <= c)
            return a;
        if (b <= a and b <= c)
            return b;
        return c;
    }
public:
    int maximumLength(string s) {
        vector<vector<int>> freq(26, vector<int>(3, -1));
        char last = '*';
        int len = 0, n = s.size();
        for (char& curr : s) {
            int idx = curr - 'a';
            len = curr == last ? len + 1 : 1;
            last = curr;
            int& minimum = getMin(freq[idx][0], freq[idx][1], freq[idx][2]);
            if (len > minimum)
                minimum = len;
        }
        int maxLen = -1;
        for (int i = 0; i < 26; ++i)
            maxLen = max(maxLen, min({freq[i][0], freq[i][1], freq[i][2]}));

        return maxLen;
    }
};
