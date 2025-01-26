class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int grpNum = 0;
        unordered_map<int, int> mp1;
        mp1[vec[0]] = grpNum;

        unordered_map<int, list<int>> mp2;
        mp2[grpNum].push_back(vec[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (abs(vec[i] - vec[i - 1]) > limit) {
                grpNum += 1;
            }
            mp1[vec[i]] = grpNum;
            mp2[grpNum].push_back(vec[i]);
        }
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int k = mp1[nums[i]];
            ans[i] = *mp2[k].begin();
            mp2[k].pop_front();
        }
        return ans;
    }
};
