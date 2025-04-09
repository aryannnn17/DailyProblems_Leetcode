class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int& i : nums) {
            if (i < k)
                return -1;
            else if (i > k)
                s.insert(i);
        }
        return s.size();
    }
};
