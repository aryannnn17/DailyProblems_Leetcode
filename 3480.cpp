class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long val = 0;
        vector<vector<int>> vec(n + 1);
        for (auto& p : conflictingPairs)
            vec[max(p[0], p[1])].push_back(min(p[0], p[1]));

        int c = 0;
        int cmax = 0;
        vector<long long> extra(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int& u : vec[i]) {
                if (u >= cmax) {
                    c = cmax;
                    cmax = u;
                } else if (u > c)
                    c = u;
            }
            val += i - cmax;
            extra[cmax] += cmax - c;
        }
        return val + *max_element(extra.begin(), extra.end());
    }
};
