class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> deg(colors.size(), 0);
        for (auto& v : edges) {
            adj[v[0]].push_back(v[1]);
            deg[v[1]]++;
        }
        queue<int> q;
        vector<vector<int>> t(colors.size(), vector<int>(26, 0));
        for (int i = 0; i < colors.size(); i++) {
            if (deg[i] == 0) {
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }
        int ans = 0;
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            ans = max(ans, t[u][colors[u] - 'a']);
            for (int& v : adj[u]) {
                for (int i = 0; i < 26; i++)
                    t[v][i] = max(t[v][i], t[u][i] + (colors[v] - 'a' == i));
                deg[v]--;
                if (deg[v] == 0)
                    q.push(v);
            }
        }
        if (cnt < colors.size())
            return -1;
        return ans;
    }
};
