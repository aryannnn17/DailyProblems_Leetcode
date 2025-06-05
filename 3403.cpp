class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if (numFriends == 1)
            return word;
        string ans;
        int longestPossible = n - (numFriends - 1);
        for (int i = 0; i < n; i++) {
            int canTakeLength = min(longestPossible, n - i);
            ans = max(ans, word.substr(i, canTakeLength));
        }
        return ans;
    }
};
