class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long ans = 0;
        long maxDiff = 0, maxi = 0;
        for (auto i: nums) {
            ans = max(ans, maxDiff * i);
            maxDiff = max(maxDiff, maxi - i);
            maxi = max(maxi, (long)i);
        }
        return ans;
    }
};

// -------< TLE >---------
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         long ans = 0;
//         for(int i=0;i<nums.size()-2;++i){
//             for(int j = i+1;j<nums.size()-1;++j){
//                 int maxi = *max_element(nums.begin()+j+1,nums.end());
//                 ans = max(((long)(nums[i]-nums[j])*maxi),ans);
//             }
//         }
//         return ans;
//     }
// };
