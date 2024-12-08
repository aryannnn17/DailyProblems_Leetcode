class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        map<int, int> nums;
        for (auto& i : events)
            nums[i[1]] = max(nums[i[1]], i[2]);

        int ans = 0, prev = 0;
        auto it = nums.begin();
        for (auto& i : events) {
            while (it != nums.end() && it->first < i[0]) {
                prev = max(prev, it->second);
                ++it;
            }
            ans = max(ans, prev + i[2]);
        }
        return ans;
    }
};
