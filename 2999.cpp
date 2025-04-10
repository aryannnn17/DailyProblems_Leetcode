class Solution {
public:
    long long solve(string& str, string& s, int limit) {
        if (str.length() < s.length())
            return 0;

        long long cnt = 0;
        string t = str.substr(str.length() - s.length());
        int rem = str.length() - s.length();

        for (int i = 0; i < rem; i++) {
            int digit = str[i] - '0';
            if (digit <= limit) {
                cnt += digit * pow(limit + 1, rem - i - 1);
            } else {
                cnt += pow(limit + 1, rem - i);
                return cnt;
            }
        }

        if (t >= s)
            cnt += 1;

        return cnt;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                  string s) {
        string st = to_string(start - 1);
        string end = to_string(finish);
        return solve(end, s, limit) - solve(st, s, limit);
    }
};
