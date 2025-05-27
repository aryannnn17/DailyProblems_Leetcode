class Solution {
public:
    int differenceOfSums(int n, int m) {
        
        int sum = 0;
        for (int i = 1; i <= n/m; ++i) 
            sum += m * i;
        
        return (n * (n + 1) / 2) - (2 * sum);
    }
};
