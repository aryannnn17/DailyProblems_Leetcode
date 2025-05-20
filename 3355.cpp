class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> diff(nums.size() + 1, 0);
        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];
            diff[start]++;
            diff[end + 1]--;
        }
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += diff[i];
            if (sum < nums[i])
                return false;
        }
        return true;
    }
};

// -----------< TLE >-------------------
// class Solution {
// public:
//     bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
//         vector<int> pre(nums.size(), 0);
//         for (int i = 0; i < queries.size(); ++i) {
//             for (int j = queries[i][0]; j <= queries[i][1]; ++j) {
//                 pre[j]++;
//             }
//         }
//         for (int i = 0; i < nums.size(); ++i)
//             if (nums[i] - pre[i] > 0)
//                 return false;
//         return true;
//     }
// };
