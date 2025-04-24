class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        vector<int> d;
        for (int i : nums)
            if (find(d.begin(), d.end(), i) == d.end())
                d.push_back(i);
        int k = d.size();
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> v;
            for (int j = i; j < nums.size(); ++j) {
                if (find(v.begin(), v.end(), nums[j]) == v.end()) {
                    v.push_back(nums[j]);
                }
                if (!v.empty() && v.size() == k) {
                    ans += nums.size() - j;
                    break;
                }
            }
        }
        return ans;
    }
};
