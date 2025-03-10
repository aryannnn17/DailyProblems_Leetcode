class Solution {
public:
    bool isVowel(char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        unordered_map<char, int> mp;
        vector<int> v(word.length());
        int right = word.length();

        for (int i = word.length() - 1; i >= 0; i--) {
            v[i] = right;
            if (!isVowel(word[i]))
                right = i;
        }
        int i = 0;
        int j = 0;
        long long count = 0;
        int cons = 0;

        while (j < word.length()) {
            char ch = word[j];
            if (isVowel(ch))
                mp[ch]++;
            else
                cons++;

            while (cons > k) {
                char ch = word[i];
                if (isVowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0)
                        mp.erase(ch);
                } else
                    cons--;
                i++;
            }

            while (i < word.length() && mp.size() == 5 && cons == k) {
                int idx = v[j];
                count += idx - j;
                char ch = word[i];
                if (isVowel(ch)) {
                    mp[ch]--;
                    if (mp[ch] == 0)
                        mp.erase(ch);
                } else
                    cons--;
                i++;
            }
            j++;
        }
        return count;
    }
};
