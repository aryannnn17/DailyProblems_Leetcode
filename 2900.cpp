class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> v;
        for (int i = 0; i < words.size(); i++)
            if (i == 0 || groups[i] != groups[i - 1])
                v.push_back(words[i]);
        return v;
    }
};
