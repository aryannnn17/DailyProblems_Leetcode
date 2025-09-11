class Solution {
public:
    string sortVowels(string s) {
        vector<char> vow;
        vector<int> idx;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
                s[i] == 'O' || s[i] == 'U') {
                idx.push_back(i);
                vow.push_back(s[i]);
            }
        }
        sort(vow.begin(), vow.end());
        for (int i = 0; i < idx.size(); ++i) 
            s[idx[i]] = vow[i];
        
        return s;
    }
};
