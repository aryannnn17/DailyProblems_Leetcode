class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int& i : nums)
            mp[i]++;
        for (int& i : nums)
            if (mp.count(i + 1))
                cnt = max(cnt, mp[i] + mp[i + 1]);

        return cnt;
    }
};
