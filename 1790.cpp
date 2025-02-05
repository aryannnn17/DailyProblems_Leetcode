class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> vec(2, 0);
        int idx = 0;
        if (s1 == s2)
            return true;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                if (idx > 1)
                    return false;
                else {
                    vec[idx] = i;
                    idx++;
                }
            }
        }
        swap(s2[vec[0]], s2[vec[1]]);
        if (s1 == s2)
            return true;
        return false;
    }
};
