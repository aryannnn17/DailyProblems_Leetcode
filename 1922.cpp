// class Solution {
// public:
//     const int MOD = 1000000007;
//     long findpow(long a, long b) {
//         if (b == 0)
//             return 1;
//         return a * findpow(a, b - 1) % MOD;
//     }
//     int countGoodNumbers(long long n) {

//         long ans1 = findpow(5, (n + 1) / 2);
//         long ans2 = findpow(4, n / 2);
//         return (ans1 * ans2 % MOD);
//     }
// };

class Solution {
public:
    const int MOD = 1e9 + 7;
    int findPower(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = findPower(a, b / 2);
        long long res = (half * half) % MOD;
        if (b % 2 == 1)
            res = (res * a) % MOD;
        return res;
    }

    int countGoodNumbers(long long n) {
        return (long long)findPower(5, (n + 1) / 2) * findPower(4, n / 2) % MOD;
    }
};
