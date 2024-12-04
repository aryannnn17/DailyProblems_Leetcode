class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = 0, i = 0, count = 0;
        while (n != str2.length() && i != str1.length()) {
            char next = str1.at(i) + 1;
            if (str1.at(i) == 'z') {
                next = 'a';
            }
            if (str1.at(i) == str2.at(n) || next == str2.at(n)) {
                count++;
                n++;
            }
            i++;
        }
        cout << count;
        if (count == str2.length())
            return true;
        return false;
    }
};
