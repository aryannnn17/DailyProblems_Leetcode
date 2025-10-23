class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int val = *max_element(begin(nums), end(nums)) + k;
        map<int, int> mp;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            mp[max(nums[i] - k, 0)]++;
            mp[min(nums[i] + k, val)+ 1]--;
            mp[nums[i]] += 0;
        }

        int ans = 1;
        int totalSum = 0;

        for (auto i = mp.begin(); i != mp.end(); i++) {
            int tar = i->first;
            i->second += totalSum;
            int conv = i->second - freq[tar];
            ans = max(ans, freq[tar] + min(conv, numOperations));
            totalSum = i->second;
        }
        return ans;
    }
};
