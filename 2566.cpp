class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        bool nine = 1, zero = 1;
        char minC = ' ', maxC = ' ';
        string minS = s, maxS = s;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '9' && nine) {
                maxC = s[i];
                nine = 0;
            }
            if (s[i] != '0' && zero) {
                minC = s[i];
                zero = 0;
            }
            if (maxC == s[i])
                maxS[i] = '9';
            if (minC == s[i])
                minS[i] = '0';
        }
        return stoi(maxS) - stoi(minS);
    }
};
