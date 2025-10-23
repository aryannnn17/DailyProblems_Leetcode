class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEl = *max_element(begin(nums), end(nums)) + k;
        vector<int> freq(maxEl + 1, 0);
        for (int& num : nums)
            freq[num]++;

        for (int i = 1; i <= maxEl; i++) 
            freq[i] += freq[i - 1];
        
        int ans = 0;
        for (int i = 0; i <= maxEl; i++) {
            if (freq[i] == 0)
                continue;
            int l = max(0, i - k);
            int r = min(maxEl, i + k);

            int count = freq[r] - (l > 0 ? freq[l - 1] : 0);
            int targetCount = freq[i] - (i > 0 ? freq[i - 1] : 0);
            int maxFreq = targetCount + min(count - targetCount, numOperations);
            ans = max(ans, maxFreq);
        }

        return ans;
    }
};
