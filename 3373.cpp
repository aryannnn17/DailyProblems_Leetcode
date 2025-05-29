class Solution {
public:
    unordered_map<int, vector<int>> getAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }

    void dfs(int curr, unordered_map<int, vector<int>>& adj, int parent,
             vector<int>& mark, int& zeroCnt, int& oneCnt) {

        if (mark[curr] == 0)
            zeroCnt++;
        else
            oneCnt++;

        for (auto& i : adj[curr]) {
            if (i != parent) {
                mark[i] = (mark[curr] == 0) ? 1 : 0;
                dfs(i, adj, curr, mark, zeroCnt, oneCnt);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {

        unordered_map<int, vector<int>> adjA = getAdj(edges1);
        unordered_map<int, vector<int>> adjB = getAdj(edges2);
        vector<int> markA(edges1.size() + 1, -1);
        markA[0] = 0;
        int zeroCntA = 0;
        int oneCntA = 0;
        dfs(0, adjA, -1, markA, zeroCntA, oneCntA);

        vector<int> markB(edges2.size() + 1, -1);
        markB[0] = 0;
        int zeroCntB = 0;
        int oneCntB = 0;
        dfs(0, adjB, -1, markB, zeroCntB, oneCntB);

        int tree2 = max(zeroCntB, oneCntB);
        vector<int> ans(edges1.size() + 1);
        for (int i = 0; i < edges1.size() + 1; i++)
            ans[i] = (markA[i] == 0 ? zeroCntA : oneCntA) + tree2;

        return ans;
    }
};
