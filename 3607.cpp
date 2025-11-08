class Solution {
public:
    void bfs(int start, unordered_map<int, vector<int>>& adj, int id,
             vector<int>& nodeId, unordered_map<int, set<int>>& mp,
             vector<bool>& visited) {

        queue<int> q;
        q.push(start);
        visited[start] = true;
        nodeId[start] = id;
        mp[id].insert(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int& n : adj[node]) {
                if (!visited[n]) {
                    visited[n] = true;
                    nodeId[n] = id;
                    mp[id].insert(n);
                    q.push(n);
                }
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (auto& e : connections) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(c + 1, false);
        vector<int> nodeId(c + 1);
        unordered_map<int, set<int>> mp;

        for (int i = 1; i <= c; i++)
            if (!visited[i])
                bfs(i, adj, i, nodeId, mp, visited);

        vector<int> ans;

        for (auto& query : queries) {
            int type = query[0];
            int node = query[1];

            if (type == 1) {
                int id = nodeId[node];
                if (mp[id].count(node))
                    ans.push_back(node);
                else if (!mp[id].empty())
                    ans.push_back(*mp[id].begin());
                else
                    ans.push_back(-1);

            } else
                mp[nodeId[node]].erase(node);
        }

        return ans;
    }
};
