class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i) {
            for (int n = 0; n < words[i].length(); ++n) {
                for (int j = 1; j < words[i].length(); ++j) {
                    string sub = words[i].substr(n, j);
                    if (find(words.begin(), words.end(), sub) != words.end() &&
                        find(ans.begin(), ans.end(), sub) == ans.end()) {
                        ans.push_back(sub);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
