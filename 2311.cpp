class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt = 0;
        long long pow = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0')
                cnt++;
            else if (pow <= k) {
                cnt++;
                k -= pow;
            }
            if (pow <= k)
                pow <<= 1;
        }

        return cnt;
    }
};
