class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> part;
        vector<int> mp(26, 0);
        for (int i = 0; i < s.length(); i++)
            mp[s[i] - 'a'] = i;

        int i = 0;
        while (i < s.length()) {
            int end = mp[s[i] - 'a'];
            int j = i;
            while (j < end) {
                end = max(end, mp[s[j] - 'a']);
                j++;
            }
            part.push_back(j - i + 1);
            i = j + 1;
        }
        return part;
    }
};
