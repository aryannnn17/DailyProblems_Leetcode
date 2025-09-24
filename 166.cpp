class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        string ans;
        if ((long long)numerator * (long long)denominator < 0)
            ans += "-";

        long num = labs(numerator);
        long den = labs(denominator);

        long div = num / den;
        ans += to_string(div);

        long rem = num % den;
        if (rem == 0)
            return ans;

        ans += '.';
        unordered_map<int, int> mp;
        while (rem != 0) {
            if (mp.count(rem)) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }
            mp[rem] = ans.length();
            rem *= 10;
            int digit = rem / den;
            ans += to_string(digit);
            rem = rem % den;
        }
        return ans;
    }
};
