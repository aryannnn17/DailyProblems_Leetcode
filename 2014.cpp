class Solution {
public:
    string ans = "";
    bool isSubSeq(string& s, string& sub, int k) {
        int i = 0;
        int j = 0;
        while (i < s.length() && j < k * sub.length()) {
            if (s[i] == sub[j % sub.length()])
                j++;
            i++;
        }
        return j == k * sub.length();
    }

    void backtrack(string& s, string& curr, vector<bool>& canUse,
                   vector<int>& reqFreq, int k, int maxLen) {
        if (curr.length() > maxLen)
            return;
        if ((curr.length() > ans.length() ||
             (curr.length() == ans.length() && curr > ans)) &&
            isSubSeq(s, curr, k)) {
            ans = curr;
        }
        for (int i = 0; i <= 25; i++) {
            if (canUse[i] == false || reqFreq[i] == 0)
                continue;
            curr.push_back(i + 'a');
            reqFreq[i]--;
            backtrack(s, curr, canUse, reqFreq, k, maxLen);
            curr.pop_back();
            reqFreq[i]++;
        }
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int freq[26] = {};
        for (char& ch : s) 
            freq[ch - 'a']++;

        vector<bool> canUse(26, false);
        vector<int> reqFreq(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (freq[i] >= k) {
                canUse[i] = true;
                reqFreq[i] = freq[i] / k;
            }
        }
        int maxLen = s.length() / k;
        string curr;
        backtrack(s, curr, canUse, reqFreq, k, maxLen);
        return ans;
    }
};
