class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int i = 0;
        long long ans = 0;
        unordered_map<int, int> mp;
        long long cnt = 0;
        for (int j = 0; j < nums.size(); ++j) {
            cnt += mp[nums[j]];
            mp[nums[j]]++;
            while (cnt >= k) {
                ans += (nums.size() - j);
                mp[nums[i]]--;
                cnt -= mp[nums[i]];
                i++;
            }
        }
        return ans;
    }
};
