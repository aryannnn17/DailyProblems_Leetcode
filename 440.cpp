class Solution {
public:
    int cntFunc(long curr, long next, int n) {
        int cnt = 0;
        while (curr <= n) {
            cnt += (next - curr);
            curr *= 10;
            next *= 10;
            next = min(next, long(n + 1));
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k -= 1; 
        while (k > 0) {
            int cnt = cntFunc(curr, curr + 1, n);
            if (cnt <= k) {
                curr++;
                k -= cnt; 
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};


/* // ---------- MLE ---------------
class Solution {
public:
    void solve(int curr, int n, vector<int>& vec) {
        if (curr > n)
            return;
        vec.push_back(curr);
        for (int i = 0; i <= 9; i++) {
            int next = curr * 10 + i;
            if (next > n)
                return;
            solve(next, n, vec);
        }
    }

    int findKthNumber(int n, int k) {
        vector<int> vec;
        for (int num = 1; num <= 9; num++)
            solve(num, n, vec);
        return vec[k - 1];
    }
};
 */
