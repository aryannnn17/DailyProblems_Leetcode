class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j = 0;
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (j < spaces.size()) {
                if (i == spaces.at(j)) {
                    ans += ' ';
                    j++;
                }
            }
            ans += s.at(i);
        }
        return ans;
    }
};
