class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans, p2, p1;
        
        for (int i : nums) {
            if (i < pivot)
                ans.push_back(i);
            else if (i > pivot)
                p2.push_back(i);
            else
                p1.push_back(i);
        }
        for (int i : p1)
            ans.push_back(i);
        for (int i : p2)
            ans.push_back(i);
        
        return ans;
    }
};
