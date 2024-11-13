class Solution {
    void Freq(vector<int>& bitFreq, int num, int val) {
        for (int i = 0; i < 32; ++i)
            if (num & (1 << i))
                bitFreq[i] += val;
    }
    int getN(vector<int>& bitFreq) {
        int n = 0;
        long long pow = 1;
        for (int i = 0; i < 32; ++i) {
            if (bitFreq[i] > 0)
                n += pow;
            pow *= 2;
        }
        return n;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0)
            return 1;

        int n = nums.size();
        int shortest = INT_MAX;
        int left = 0, right = 0;
        int curr = 0;
        vector<int> bitFreq(32);

        while (right < n) {
            Freq(bitFreq, nums[right], 1);
            curr |= nums[right];

            while (left <= right and curr >= k) {
                shortest = min(shortest, right - left + 1);
                Freq(bitFreq, nums[left], -1);
                curr = getN(bitFreq);
                left++;
            }
            right++;
        }
        return shortest == INT_MAX ? -1 : shortest;
    }
};
