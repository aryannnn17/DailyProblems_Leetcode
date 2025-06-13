class Solution {
public:
    int getState(int cnt_a, int cnt_b) {
        int par_a = cnt_a % 2;
        int par_b = cnt_b % 2;

        if (par_a == 0 && par_b == 0)
            return 0;
        if (par_a == 0 && par_b == 1)
            return 1;
        if (par_a == 1 && par_b == 0)
            return 2;
        return 3;
    }

    int maxDifference(string s, int k) {
        int n = s.length();
        int ans = INT_MIN;
        for (char a = '0'; a <= '4'; a++) {
            for (char b = '0'; b <= '4'; b++) {
                if (a == b)
                    continue;

                vector<int> states(4, INT_MAX);

                int cnt_a = 0;
                int cnt_b = 0;

                int prev_a = 0;
                int prev_b = 0;

                int l = -1;
                int r = 0;

                while (r < n) {
                    cnt_a += (s[r] == a) ? 1 : 0;
                    cnt_b += (s[r] == b) ? 1 : 0;

                    while (r - l >= k && cnt_b - prev_b >= 2 &&
                           cnt_a - prev_a >= 1) {
                        int left = getState(prev_a, prev_b);
                        states[left] = min(states[left], prev_a - prev_b);

                        l++;
                        prev_a += (s[l] == a) ? 1 : 0;
                        prev_b += (s[l] == b) ? 1 : 0;
                    }

                    int right = getState(cnt_a, cnt_b);
                    int stateLeft = right ^ 2;

                    if (states[stateLeft] != INT_MAX)
                        ans = max(ans, (cnt_a - cnt_b) - states[stateLeft]);

                    r++;
                }
            }
        }

        return ans;
    }
};
