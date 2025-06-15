class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        char minC = ' ', maxC = ' ';
        string minS = s, maxS = s;
        bool nine = 1, zero = 1;
        char r = '1';
        if (s[0] == '1')
            r = '0';
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '9' && nine) {
                maxC = s[i];
                nine = 0;
            }
            if (s[i] != '1' && zero && s[i] != '0') {
                minC = s[i];
                zero = 0;
            }
            if (s[i] == maxC)
                maxS[i] = '9';

            if (s[i] == minC)
                minS[i] = r;
        }
        char c = s[0];
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i)
            if (c == s[i]) {
                s[i] = '1';
                cnt++;
            }

        if (cnt == s.length())
            minS = s;

        return stoi(maxS) - stoi(minS);
    }
};
