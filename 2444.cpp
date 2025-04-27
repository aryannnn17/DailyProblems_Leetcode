class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int minPos = -1;
        int maxPos = -1;
        int l = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < minK || nums[i] > maxK)
                l = i;
            if (nums[i] == minK)
                minPos = i;
            if (nums[i] == maxK)
                maxPos = i;
            int count = min(maxPos, minPos) - l;
            ans += (count <= 0) ? 0 : count;
        }
        return ans;
    }
};
