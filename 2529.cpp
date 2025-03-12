class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0;
        for (int i : nums) {
            if (i == 0)
                continue;
            else if (i > 0)
                pos++;
            else
                neg++;
        }
        return max(pos, neg);
    }
};
