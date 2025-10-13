class Solution {
public:
    bool anagram(string& s1, string& s2) {
        vector<int> freq(26, 0);
        for (char& c : s1)
            freq[c - 'a']++;
        for (char& c : s2)
            freq[c - 'a']--;
        for (int i = 0; i < 26; i++)
            if (freq[i] != 0)
                return 0;
        return 1;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < words.size(); i++)
            if (!anagram(words[i], ans.back()))
                ans.push_back(words[i]);
        return ans;
    }
};
