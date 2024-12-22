
class Solution {
    int dfs(vector<vector<int>>& adj, vector<int>& values, int& k, int& count,
            int curr, int parent = -1) {
        long long sum = values.at(curr);
        for (int i : adj.at(curr)) {
            if (i != parent)
                sum += dfs(adj, values, k, count, i, curr);
        }
        sum %= k;
        if (sum == 0)
            count++;
        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto i : edges) {
            adj.at(i.at(0)).push_back(i.at(1));
            adj.at(i.at(1)).push_back(i.at(0));
        }
        int ans = 0;
        dfs(adj, values, k, ans, 0);
        return ans;
    }
};
