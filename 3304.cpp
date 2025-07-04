class Solution {
public:
    char kthCharacter(int k) {
        string s = "ab";
        while (s.length() < k) {
            string s2 = "";
            for (char c : s) {
                if (c == 'z')
                    s2.push_back('a');
                else
                    s2.push_back(c + 1);
            }
            s.append(s2);
        }
        return s[k - 1];
    }
};
