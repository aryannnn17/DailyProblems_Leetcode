class Solution {
public:
    int ans;
    void rec(vector<int>& count) {
        ans++;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0)
                continue;
            count[i]--;
            rec(count);
            count[i]++;
        }
    }
    int numTilePossibilities(string tiles) {
        ans = 0;
        vector<int> count(26, 0);
        for (char& c : tiles)
            count[c - 'A']++;

        rec(count);
        return ans - 1;
    }
};
