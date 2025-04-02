// ------< TC : O(n^2) >----------
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long ans = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int maxi = *max_element(nums.begin() + j + 1, nums.end());
                ans = max(ans, (long)(nums[i] - nums[j]) * maxi);
            }
        }
        return ans;
    }
};

// -----------< TC : O(N) >---------------
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         long ans = 0;
//         long maxDiff = 0, maxi = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             ans = max(ans, maxDiff * nums[i]);
//             maxDiff = max(maxDiff, maxi - nums[i]);
//             maxi = max(maxi, (long)nums[i]);
//         }
//         return ans;
//     }
// };

//------< Brute Force >-----------
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         long ans = 0;
//         for (int i = 0; i < nums.size() - 2; ++i) {
//             for (int j = i + 1; j < nums.size() - 1; ++j) {
//                 for (int k = j + 1; k < nums.size(); ++k)
//                     ans = max(ans, (long)(nums[i]-nums[j])*nums[k]);
//             }
//         }
//         return ans;
//     }
// };
