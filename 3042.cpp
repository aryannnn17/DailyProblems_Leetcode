class Solution {
    bool isPrefixAndSuffix(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;
        if (s1 == s2.substr(0, s1.length()) &&
            s1 == s2.substr(s2.length() - s1.length(), s1.length()))
            return true;
        return false;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        if (words.size() == 1)
            return 0;

        int count = 0;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                count += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return count;
    }
};
