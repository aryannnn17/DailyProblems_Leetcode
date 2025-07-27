class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> adj;
        for (int i : nums)
            if (adj.empty() || adj.back() != i)
                adj.push_back(i);

        int cnt = 0;
        for (int i = 1; i < adj.size() - 1; ++i)
            if (adj[i] < adj[i - 1] == adj[i] < adj[i + 1])
                cnt++;

        return cnt;
    }
};
