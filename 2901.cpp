class Solution {
public:
    bool checkHD(string& s1, string& s2) {
        int diff = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i])
                diff++;
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {

        vector<int> dp(words.size(), 1);
        vector<int> arr(words.size(), -1);
        int sub = 1;
        int idx = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (groups[j] != groups[i] &&
                    words[i].length() == words[j].length() &&
                    checkHD(words[i], words[j])) {

                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        arr[i] = j;
                        if (sub < dp[i]) {
                            sub = dp[i];
                            idx = i;
                        }
                    }
                }
            }
        }

        vector<string> ans;
        while (idx != -1) {
            ans.push_back(words[idx]);
            idx = arr[idx];
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
