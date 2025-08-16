class Solution {
public:
    int maximum69Number(int num) {
        string s = to_string(num);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '6') {
                s[i] = '9';
                return num + 3 * pow(10, s.length() - i - 1);
            }
        }
        return num;
    }
};
