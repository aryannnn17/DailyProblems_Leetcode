class Solution {
public:
    int M = 1e9 + 7;
    int possibleStringCount(string word, int k) {
        if (k > word.length())
            return 0;

        vector<int> freq;
        int cnt = 1;
        for (int i = 1; i < word.length(); i++) {
            if (word[i] == word[i - 1])
                cnt++;
            else {
                freq.push_back(cnt);
                cnt = 1;
            }
        }
        freq.push_back(cnt);

        long long P = 1;
        for (int& f : freq)
            P = (P * f) % M;

        if (freq.size() >= k)
            return P;

        int n = freq.size();
        vector<vector<int>> t(n + 1, vector<int>(k + 1, 0));

        for (int cnt = k - 1; cnt >= 0; cnt--)
            t[n][cnt] = 1;

        for (int i = n - 1; i >= 0; i--) {
            vector<int> pre(k + 1, 0);
            for (int h = 1; h <= k; h++)
                pre[h] = (pre[h - 1] + t[i + 1][h - 1]) % M;

            for (int cnt = k - 1; cnt >= 0; cnt--) {
                int l = cnt + 1;
                int r = cnt + freq[i];

                if (r + 1 > k)
                    r = k - 1;

                if (l <= r)
                    t[i][cnt] = (pre[r + 1] - pre[l] + M) % M;
            }
        }
        long long invalidcnt = t[0][0];
        return (P - invalidcnt + M) % M;
    }
};
