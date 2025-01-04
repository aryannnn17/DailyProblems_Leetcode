class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for (char& c : s) {
            letters.insert(c);
        }
        int res = 0;
        for (char letter : letters) {
            int first = -1, last = -1;
            for (int i = 0; i < s.length(); i++)
                if (s[i] == letter) {
                    if (first == -1)
                        first = i;
                    last = i;
                }
            unordered_set<char> st;
            for (int mid = first + 1; mid <= last - 1; mid++) {
                st.insert(s[mid]);
            }
            res += st.size();
        }
        return res;
    }
};
