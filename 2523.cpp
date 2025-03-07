class Solution {
public:
    bool isPrime(int n) {
        if (n == 1)
            return false;
        for (int div = 2; div * div <= n; div++)
            if (n % div == 0)
                return false;
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime(i) == true) {
                if (!primes.empty() && i - primes.back() <= 2) {
                    return {primes.back(), i};
                }
                primes.push_back(i);
            }
        }

        int minDiff = INT_MAX;
        vector<int> res = {-1, -1};
        for (int i = 1; i < primes.size(); i++) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                res = {primes[i - 1], primes[i]};
                minDiff = diff;
            }
        }
        return res;
    }
};
