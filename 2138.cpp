class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;

        int l = s.length();
        while (l % k != 0) {
            s.push_back(fill);
            l++;
        }

        for (int i = 0; i < l; i += k)
            v.push_back(s.substr(i, k));

        return v;
    }
};
