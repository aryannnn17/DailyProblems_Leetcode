class Solution {
public:
    bool DFS(unordered_map<int, vector<int>>& adj, int u, int v,
             vector<bool>& visited) {
        visited[u] = 1;
        if (u == v)
            return 1;
        for (int& i : adj[u]) {
            if (visited[i])
                continue;
            if (DFS(adj, i, v, visited))
                return 1;
        }
        return 0;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < edges.size(); i++) {
            vector<bool> visited(edges.size(), false);
            if (mp.find(edges[i][0]) != mp.end() &&
                mp.find(edges[i][1]) != mp.end() &&
                DFS(mp, edges[i][0], edges[i][1], visited)) {
                return edges[i];
            }
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        return {};
    }
};
