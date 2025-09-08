class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v(n, 0);
        int len = -n / 2;

        if (n % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                if (len == 0) 
                    len++;
                
                v[i] = len;
                len++;
            }
        } else {
            for (int i = 0; i < n; ++i) {
                v[i] = len;
                len++;
            }
        }
        return v;
    }
};
