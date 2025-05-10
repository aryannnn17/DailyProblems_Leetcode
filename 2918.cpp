class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long z1 = 0, z2 = 0;
        long sum1 = 0, sum2 = 0;
        long ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == 0) {
                nums1[i] = 1;
                z1++;
            }
            sum1 += nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == 0) {
                nums2[i] = 1;
                z2++;
            }
            sum2 += nums2[i];
        }
        if ((z1 == 0 && sum1 < sum2) || (z2 == 0 && sum1 > sum2))
            return -1;
        return max(sum1, sum2);
    }
};
