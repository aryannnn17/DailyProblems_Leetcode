class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size(), count = 0;
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> deg(n, 0);

        for (int i = 0; i < n; i++)
            for (int& j : graph[i]) {
                adj[j].push_back(i);
                deg[i]++;
            }
        for (int i = 0; i < n; i++)
            if (deg[i] == 0) {
                q.push(i);
                count++;
            }
        vector<bool> safe(n, false);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            safe[i] = true;

            for (int& j : adj[i]) {
                deg[j]--;

                if (deg[j] == 0) {
                    q.push(j);
                    count++;
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (safe[i])
                ans.push_back(i);

        return ans;
    }
};
