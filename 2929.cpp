class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;
        int maxC1 = min(n, limit);
        int minC1 = max(0, n - 2 * limit);
        for (int i = minC1; i <= maxC1; i++) {
            int rem = n - i;
            int minC2 = max(0, rem - limit);
            int maxC2 = min(rem, limit);
            ways += maxC2 - minC2 + 1;
        }
        return ways;
    }
};
