class Solution {
#define ll long long
#define pii pair<int, int>
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pii, vector<pii>, greater<pii>> minheap;
        for (int i = 0; i < n; ++i)
            minheap.push(make_pair(nums[i], i));
        unordered_set<int> marked_idx;
        ll sum = 0;
        while (!minheap.empty()) {
            pii curr = minheap.top();
            minheap.pop();
            int val = curr.first, idx = curr.second;
            if (marked_idx.count(idx))
                continue;
            sum += val;
            marked_idx.insert(idx);
            marked_idx.insert(idx - 1);
            marked_idx.insert(idx + 1);
        }
        return sum;
    }
};
