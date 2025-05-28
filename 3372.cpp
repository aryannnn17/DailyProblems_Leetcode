class Solution {
public:
    int dfs(int curr, unordered_map<int, vector<int>>& adj, int d,
            int currNode) {
        if (d < 0)
            return 0;
        int cnt = 1;
        for (int& i : adj[curr])
            if (i != currNode)
                cnt += dfs(i, adj, d - 1, curr);
        return cnt;
    }

    vector<int> findCnt(vector<vector<int>>& edges, int d) {

        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vec(edges.size() + 1);
        for (int i = 0; i < edges.size() + 1; i++) {
            vec[i] = dfs(i, adj, d, -1);
        }
        return vec;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {

        vector<int> ans1 = findCnt(edges1, k);
        vector<int> ans2 = findCnt(edges2, k - 1);
        int tar = *max_element(begin(ans2), end(ans2));
        for (int i = 0; i < ans1.size(); i++)
            ans1[i] += tar;

        return ans1;
    }
};
