class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;
        int d = (n + 1) / 2;
        int start = pow(10, d - 1);
        int end = pow(10, d) - 1;
        for (int i = start; i <= end; i++) {
            string l = to_string(i);
            string full = "";
            if (n % 2 == 0) {
                string r = l;
                reverse(r.begin(), r.end());
                full = l + r;
            } else {
                string r = l.substr(0, d - 1);
                reverse(r.begin(), r.end());
                full = l + r;
            }
            long long num = stoll(full);
            if (num % k != 0)
                continue;
            sort(full.begin(), full.end());
            st.insert(full);
        }

        vector<long long> fac(11, 1);
        for (int i = 1; i < 11; i++) {
            fac[i] = fac[i - 1] * i;
        }
        long long res = 0;
        for (const string& s : st) {
            vector<int> cnt(10, 0);
            for (const char& ch : s)
                cnt[ch - '0']++;

            int zeros = cnt[0];
            int nonzeros = s.length() - zeros;

            long long perm = (nonzeros * fac[s.length() - 1]);
            for (int j = 0; j < 10; j++)
                perm /= fac[cnt[j]];

            res += perm;
        }

        return res;
    }
};
