// -----< BRUTE FORCE APPROCH (TLE) >--------

// class Solution {
// public:
//     vector<bool> isArraySpecial(vector<int>& nums,
//                                 vector<vector<int>>& queries) {
//         vector<bool> res;
//         bool parity;
//         for (int i = 0; i < queries.size(); i++) {
//             if (queries[i][0] == queries[i][1]) {
//                 res.push_back(true);
//             } else {
//                 for (int j = queries[i][0]; j <= queries[i][1] - 1; j++) {
//                     if ((nums.at(j) + nums.at(j + 1)) % 2 == 1) {
//                         parity = true;
//                     } else {
//                         parity = false;
//                         break;
//                     }
//                 }
//                 if (parity == true)
//                     res.push_back(true);
//                 else
//                     res.push_back(false);
//             }
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> sum(n, 0);
        sum[0] = 1;
        for (int i = 1; i < n; ++i) {
            if ((nums.at(i) & 1) == (nums.at(i - 1) & 1))
                sum.at(i) = 1;
            else
                sum.at(i) = 1 + sum.at(i - 1);
        }
        vector<bool> ans;
        for (auto& query : queries) {
            int st = query.at(0), end = query.at(1), size = end - st + 1;
            if (sum.at(end) >= size)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
