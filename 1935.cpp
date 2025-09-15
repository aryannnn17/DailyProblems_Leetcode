class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
        bool mp[26];
        for (char& c : brokenLetters)
            mp[c - 'a'] = true;
        int cnt = 0;
        bool foundBroken = false;
        for (char& c : text) {
            if (c == ' ') {
                if (!foundBroken)
                    cnt++;
                foundBroken = false;
            } else if (mp[c - 'a'])
                foundBroken = true;
        }
        if (foundBroken == 0)
            cnt++;

        return cnt;
    }
};
