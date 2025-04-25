class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
        unordered_map<int, long long> mp;
        long long sum = 0;
        long long cnt = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % m == k)
                sum += 1;
            int n1 = sum % m;
            int n2 = (n1 - k + m) % m;
            cnt += mp[n2];
            mp[n1]++;
        }
        return cnt;
    }
};

// ---------< TLE >---------------------
// class Solution {
// public:
//     long long countInterestingSubarrays(vector<int>& nums, int modulo, int k)
//     {
//         long long ans = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             long long cnt = 0;
//             for (int j = i; j < nums.size(); ++j) {
//                 if (nums[j] % modulo == k)
//                     cnt++;

//                 if (cnt % modulo == k)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };
