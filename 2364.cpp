// class Solution {
// public:
//     long long countBadPairs(vector<int>& nums) {
//         long long goodPair = 0;
//         unordered_map<long long, long long> mp;
//         for (int i = 0; i < nums.size(); ++i)
//             mp[nums[i] - i]++;

//         for (auto& m : mp)
//             if (m.second > 1)
//                 goodPair += (m.second) * (m.second - 1) / 2;

//         return (nums.size() * (nums.size() - 1) / 2) - goodPair;
//     }
// };

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += i - mp[i - nums[i]]++;
        }
        return count;
    }
};
