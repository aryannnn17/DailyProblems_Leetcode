class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ans = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            int ones = 0;
            if (s[i] == '0')
                zeros++;

            for (int j = i + 1; j < s.length(); ++j) {
                if (s[j] == '1')
                    ones++;
                ans = max(ans, zeros + ones);
            }
        }
        return ans;
    }
};
