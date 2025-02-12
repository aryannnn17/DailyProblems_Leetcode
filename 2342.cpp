class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            int temp = nums[i];
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
            mp[sum].push_back(nums[i]);
        }
        int ans = -1;
        for (auto& i : mp) {
            vector<int> arr = i.second;
            if (arr.size() >= 2) {
                sort(arr.begin(), arr.end());
                ans = max(arr[arr.size() - 1] + arr[arr.size() - 2], ans);
            }
        }
        return ans;
    }
};
