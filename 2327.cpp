class Solution {
public:
    int M = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> t(n + 1);
        t[1] = 1;
        for (int day = 2; day <= n; day++) {
            long long count = 0;
            for (int prev = day - forget + 1; prev <= day - delay; prev++) 
                if (prev > 0)
                    count = (count + t[prev]) % M;
            
            t[day] = count;
        }

        int ans = 0;
        for (int day = n - forget + 1; day <= n; day++)
            if (day > 0)
                ans = (ans + t[day]) % M;

        return ans;
    }
};
