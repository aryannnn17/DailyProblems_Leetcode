class Solution {
public:
    bool solve(int i, int n, vector<int>& res, vector<bool>& vec) {
        if (i >= res.size())
            return true;

        if (res[i] != -1)
            return solve(i + 1, n, res, vec);

        for (int num = n; num >= 1; num--) {
            if (vec[num])
                continue;
            vec[num] = true;
            res[i] = num;
            if (num == 1) {
                if (solve(i + 1, n, res, vec) == true)
                    return true;
            } else {
                int j = res[i] + i;
                if (j < res.size() && res[j] == -1) {
                    res[j] = num;
                    if (solve(i + 1, n, res, vec) == true)
                        return true;
                    res[j] = -1;
                }
            }

            vec[num] = false;
            res[i] = -1;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> res(2 * n - 1, -1);
        vector<bool> vec(n + 1, false);
        solve(0, n, res, vec);
        return res;
    }
};
