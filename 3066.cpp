class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for (auto& n : nums)
            q.push(n);
        int cnt = 0;
        while (q.top() < k) {
            long long m = q.top() * 2;
            q.pop();
            q.push(q.top() + m);
            q.pop();
            cnt++;
        }
        return cnt;
    }
};
