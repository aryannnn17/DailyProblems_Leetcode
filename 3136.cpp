class Solution {
public:
    bool isValid(string word) {
        bool vow = 0, con = 0;
        if (word.length() < 3)
            return false;
        for (char c : word) {
            if (!isalnum(c))
                return 0;
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                vow = 1;
            else if (c >= 'a' && c <= 'z')
                con = 1;
        }
        return (vow && con) ? 1 : 0;
    }
};
