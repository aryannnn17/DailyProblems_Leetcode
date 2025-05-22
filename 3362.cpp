class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int> maxHeap;
        sort(queries.begin(), queries.end());
        int j = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i) {
            while (j < queries.size() && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);
                ++j;
            }
            nums[i] -= pq.size();
            while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
                int r = maxHeap.top();
                maxHeap.pop();
                pq.push(r);
                cnt++;
                nums[i]--;
            }
            if (nums[i] > 0)
                return -1;
            while (!pq.empty() && pq.top() == i) {
                pq.pop();
            }
        }
        return queries.size() - cnt;
    }
};
