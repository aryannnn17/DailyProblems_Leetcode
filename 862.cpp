//------TRY_1-----------NOT_OPTIMAL_FOR_LARGE_INPUTS----
// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {

//         for (int len = 1; len <= nums.size(); len++) {
//             for (int i = 0; i <= nums.size() - len; i++) {
//                 int count = 0, sum = 0;
//                 for (int j = i; j < i + len; j++) {
//                     sum += nums.at(j);
//                     count++;
//                 }
//                 if (sum >= k)
//                     return count;
//             }
//         }
//         return -1;
//     }
// };

//------TRY_2-----------NOT_OPTIMAL_FOR_LARGE_INPUTS----
// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         int sum = 0;
//         int ans = INT_MAX;
//         for (int i = 0; i < nums.size(); i++) {
//             sum += nums.at(i);
//             cout << sum << " ";
//             int temp = sum;
//             for (int j = 0; j <= i; j++) {
//                 if (temp >= k) {
//                     ans = min(ans, i - j + 1);
//                 }
//                 temp -= nums.at(j);
//             }
//         }
//         if (ans == INT_MAX)
//             return -1;
//         return ans;
//     }
// };

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long, int>> dq;
        long long sum = 0;
        int ans = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums.at(i);
            if (sum >= k) {
                ans = min(ans, i + 1);
            }
            while (!dq.empty() && sum - dq.front().first >= k) {
                ans = min(ans, i - dq.front().second);
                dq.pop_front();
            }
            while (!dq.empty() && dq.back().first >= sum) {
                dq.pop_back();
            }
            dq.push_back({sum, i});
        }
        return ans <= nums.size() ? ans : -1;
    }
};
