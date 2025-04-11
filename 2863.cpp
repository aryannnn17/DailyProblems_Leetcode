class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        if (high > 9) {
            for (int i = low; i <= high; ++i) {
                string s = to_string(i);
                if (s.length() % 2 == 1)
                    continue;

                int l = 0;
                int fSum = 0, sSum = 0;
                while (l != s.length() / 2) {
                    fSum += s[l] - 48;
                    sSum += s[s.length() - 1 - l] - 48;
                    l++;
                }
                if (fSum == sSum)
                    cnt++;
            }
        }
        return cnt;
    }
};
