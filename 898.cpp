class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            for (int x : prev) {
                curr.insert(x | arr[i]);
                ans.insert(x | arr[i]);
            }
            curr.insert(arr[i]);
            ans.insert(arr[i]);
            prev = curr;
            curr.clear();
        }
        return ans.size();
    }
};
