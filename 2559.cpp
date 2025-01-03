class Solution {
    bool isVowel(char& ch) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }

public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> res(queries.size()), sum(words.size());
        int n = 0;
        for (int i = 0; i < words.size(); i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back()))
                n++;
            sum[i] = n;
        }

        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0], right = queries[i][1];
            res[i] = sum[right] - ((left > 0) ? sum[left - 1] : 0);
        }
        return res;
    }
};
