// ----< TLE > ---------

// class Solution {
// public:
//     vector<string> wordSubsets(vector<string>& words1, vector<string>&
//     words2) {
//         vector<string> ans;
//         int cmp = 0;
//         for (auto i : words2)
//             for (auto k : i)
//                 cmp++;

//         for (int j = 0; j < words1.size(); ++j) {
//             unordered_map<char, int> mp;
//             for (auto i : words1[j]) {
//                 mp[i]++;
//             }
//             int count = 0;
//             bool check = false;
//             for (auto i : words2) {
//                 unordered_map<char, int> mp1 = mp;
//                 for (auto k : i) {
//                     if (mp1.contains(k) && mp1[k] > 0) {
//                         mp1[k]--;
//                         count++;
//                     }
//                 }
//                 if (count == cmp) {
//                     check = true;
//                 }
//             }
//             if (check)
//                 ans.emplace_back(words1[j]);
//         }
//         return ans;
//     }
// };

class Solution {
    void MaxFreq(vector<int>& freqW2, vector<int>& freq) {
        for (int i = 0; i < 26; ++i)
            freqW2[i] = max(freqW2[i], freq[i]);
    }
    bool isUni(vector<int>& freqW1, vector<int>& freqW2) {
        for (int i = 0; i < 26; ++i) {
            if (freqW1[i] < freqW2[i])
                return false;
        }
        return true;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {

        vector<int> freqW2(26);
        for (string word : words2) {
            vector<int> freq(26);
            for (char c : word)
                freq[c - 'a']++;
            MaxFreq(freqW2, freq);
        }

        vector<string> ans;
        for (string word : words1) {
            vector<int> freqW1(26);
            for (char c : word)
                freqW1[c - 'a']++;

            if (isUni(freqW1, freqW2))
                ans.push_back(word);
        }
        return ans;
    }
};
