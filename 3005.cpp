class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for (int i : nums)
            freq[i]++;
        int cnt = 0;
        int maxF = *max_element(freq.begin(), freq.end());
        for (int i : freq) 
            if (maxF == i)
                cnt += maxF;
        return cnt;
    }
};
