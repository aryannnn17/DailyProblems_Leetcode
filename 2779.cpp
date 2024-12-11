//-----< BRUTE FORCE APPROACH (TLE) >---------

// class Solution {
// public:
//     int maximumBeauty(vector<int>& nums, int k) {
//         sort(nums.begin(), nums.end());
//         int count = 1, ans = 1;
//         for (int i = 0; i < nums.size() - 1; i++) {
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (nums.at(i) + k >= nums.at(j) - k) {
//                     count++;
//                 } else {
//                     break;
//                 }
//             }
//             ans = max(count, ans);
//             count = 1;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0, count = 0, left = 0, right = 0, n = nums.size();
        while (right < n) {
            while (right < n and (nums.at(right) - nums.at(left)) <= 2 * k) {
                count++;
                right++;
            }
            res = max(res, count);
            if (right == n)
                break;
            while (left <= right and (nums.at(right) - nums.at(left)) > 2 * k) {
                count--;
                left++;
            }
        }
        return res;
    }
};
