class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        int ans = 0;
        for (string& word : words) {
            string rev = word;
            swap(rev[0], rev[1]);
            if (mp[rev] > 0) {
                ans += 2;
                mp[rev]--;
            } else
                mp[word]++;
        }
        for (auto& i : mp) {
            string word = i.first;
            int cnt = i.second;
            if (word[0] == word[1] && cnt > 0) {
                ans++;
                break;
            }
        }
        return ans * 2;
    }
};
