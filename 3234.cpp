class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> cntOne(n, 0);
        cntOne[0] = (s[0] == '1') ? 1 : 0;

        for (int i = 1; i < n; i++)
            cntOne[i] = cntOne[i - 1] + ((s[i] == '1') ? 1 : 0);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int one = cntOne[j] - (i - 1 >= 0 ? cntOne[i - 1] : 0);
                int cntZero = (j - i + 1) - one;
                if ((cntZero * cntZero) > one)
                    j += (cntZero * cntZero) - one - 1;
                else if ((cntZero * cntZero) == one)
                    ans += 1;
                else {
                    ans += 1;
                    int k = sqrt(one) - cntZero;
                    if (j + k >= n) {
                        ans += (n - j - 1);
                        break;
                    } else 
                        ans += k;
                    
                    j = j + k;
                }
            }
        }
        return ans;
    }
};
