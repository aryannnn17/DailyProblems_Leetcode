class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;
        int zeroIdx = -1;
        int ans = 0;
        
        while(j < nums.size()) {
            if(nums[j] == 0) {
                i = zeroIdx+1;
                zeroIdx = j;
            }
            ans = max(ans, j-i);
            j++;
        }
        return ans;
    }
};
