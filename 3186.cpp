class Solution {
public:
    typedef long ll;
    long long maximumTotalDamage(vector<int>& power) {

        unordered_map<ll, ll> mp;
        for (int& i : power)
            mp[i]++;
        vector<ll> nums(mp.size());
        for (auto& p : mp)
            nums.push_back(p.first);
        sort(begin(nums), end(nums));
        
        vector<ll> t(nums.size(), 0);
        long  ans = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            ll skip = (i + 1 < nums.size()) ? t[i + 1] : 0;
            int j = lower_bound(begin(nums) + i + 1, end(nums), nums[i] + 3) -
                    begin(nums);
            ll take = nums[i] * mp[nums[i]] + ((j < nums.size()) ? t[j] : 0);

            t[i] = max(skip, take);
            ans = max(ans, t[i]);
        }
        return ans;
    }
};
