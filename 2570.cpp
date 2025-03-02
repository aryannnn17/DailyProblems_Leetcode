class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1,
                                    vector<vector<int>>& nums2) {
        vector<int> val(1001, 0);
        for (int i = 0; i < nums1.size(); ++i)
            val[nums1[i][0]] += nums1[i][1];
        for (int i = 0; i < nums2.size(); ++i)
            val[nums2[i][0]] += nums2[i][1];

        vector<vector<int>> ans;
        for (int i = 0; i < val.size(); ++i) {
            if (val[i] > 0) {
                ans.push_back({i, val[i]});
            }
        }

        return ans;
    }
};
