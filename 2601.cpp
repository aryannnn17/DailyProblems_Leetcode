class Solution {
public:
    void func1(vector<int>& primes, int maxVal) {
        bool s[maxVal + 1];
        memset(s, false, sizeof(s));
        for (int i = 2; i * 1 < maxVal; ++i) {
            if (s[i] == false) {
                for (int j = 2; (i * j) < maxVal; ++j)
                    s[i * j] = true;
            }
        }
        for (int i = 2; i < maxVal; ++i) {
            if (s[i] == false) {
                primes.push_back(i);
            }
        }
    }

public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes;
        int maxVal = *max_element(nums.begin(), nums.end());
        func1(primes, maxVal);

        for (int i = 0; i < nums.size(); ++i) {
            int diff = i == 0 ? nums.at(0) - 1 : nums.at(i) - nums[i - 1] - 1;
            int lb = lower_bound(primes.begin(), primes.end(), diff) -
                     primes.begin();
            if (lb == primes.size() or primes[lb] > diff) {
                lb--;
            }
            if (lb < 0) {
                if (i == 0 or nums[i] > nums[i - 1]) {
                    continue;
                } else {
                    return false;
                }
            }
            nums.at(i) -= primes.at(lb);
        }
        return true;
    }
};
