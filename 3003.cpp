class Solution {
public:
    unordered_map<long long, int> mp;
    string S;
    int K;

    int solve(long long i, long long uniqueChars, bool canChange) {
        long long key = (i << 27) | (uniqueChars << 1) | (canChange);

        if (mp.count(key))
            return mp[key];

        if (i == S.size())
            return 0;

        int idx = S[i] - 'a';
        int charUpdated = uniqueChars | (1 << idx);
        int charCount = __builtin_popcount(charUpdated);

        int ans;
        if (charCount > K)
            ans = 1 + solve(i + 1, 1 << idx, canChange);
        else
            ans = solve(i + 1, charUpdated, canChange);

        if (canChange) {
            for (int newCharIndex = 0; newCharIndex < 26; ++newCharIndex) {
                int newSet = uniqueChars | (1 << newCharIndex);
                int newcharCount = __builtin_popcount(newSet);

                if (newcharCount > K) 
                    ans = max(ans, 1 + solve(i + 1, 1 << newCharIndex, false));
                else 
                    ans = max(ans, solve(i + 1, newSet, false));
                
            }
        }
        return mp[key] = ans;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        S = s;
        K = k;
        return solve(0, 0, true) + 1;
    }
};
