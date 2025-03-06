// Arithmetic Progression Concept (Tn and Sn Formula)
class Solution {
public:
    long long coloredCells(int _n) {
        
        long long n = _n;
        long long ans = (n-1)*(2 + (n-2)*2);
        // for (int i = 1; i < n; ++i) {
        //     ans += 1 + (i - 1) * 2;
        // }
        return ans + 1 + ((n - 1) * 2);
    }
};
