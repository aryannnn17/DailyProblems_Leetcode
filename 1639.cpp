class Solution {
#define ll long long
    int mem[1001][1001];
    int MOD = 1000000007, target_size, word_size, n;
    vector<vector<int>> freq;

public:
    int countWays(vector<string>& words, int idx, string& target, int tpos) {
        if (tpos == target_size)
            return idx <= word_size;
        if (idx >= word_size || (word_size - idx < target_size - tpos))
            return 0;
        if (mem[idx][tpos] != -1)
            return mem[idx][tpos];

        char curr = target[tpos];

        ll not_matching = countWays(words, idx + 1, target, tpos),
           matching = countWays(words, idx + 1, target, tpos + 1) % MOD,
           ways = (not_matching + (ll)freq[idx][curr - 'a'] * matching) % MOD;

        return mem[idx][tpos] = ways;
    }
    int numWays(vector<string>& words, string target) {
        target_size = target.size();
        word_size = words[0].size();
        freq = vector<vector<int>>(word_size, vector<int>(26, 0));
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < word_size; ++j) {
                char curr = words[i][j];
                freq[j][curr - 'a']++;
            }
        }
        memset(mem, -1, sizeof(mem));
        return countWays(words, 0, target, 0);
    }
};
