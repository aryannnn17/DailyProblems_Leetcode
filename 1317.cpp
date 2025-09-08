class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 0; i < n; ++i) {
            string s1 = to_string(i);
            string s2 = to_string(n - i);
            bool check = true;
            for (auto c : s1)
                if (c == '0') {
                    check = false;
                    break;
                }
            for (auto c : s2)
                if (c == '0') {
                    check = false;
                    break;
                }
            if (check)
                return {i, n - i};
        }
        return {-1, -1};
    }
};
