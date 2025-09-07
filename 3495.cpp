class Solution {
public:
    long long solve(int l, int r) {

        long L = 1;
        long S = 1;
        long steps = 0;
        while (L <= r) {
            long R = 4 * L - 1;
            long start = max(L, (long)l);
            long end = min(R, (long)r);
            if (start <= end)
                steps += (end - start + 1) * S;
            S += 1;
            L = L * 4;
        }
        return steps;
    }

    long minOperations(vector<vector<int>>& queries) {
        long ans = 0;
        for (auto& q : queries) {
            long steps = solve(q[0], q[1]);
            ans += (steps + 1) / 2;
        }

        return ans;
    }
};
