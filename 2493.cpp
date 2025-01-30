class Solution {
public:
    bool func(unordered_map<int, vector<int>>& adj, int curr,
                     vector<int>& colors, int currColor) {
        colors[curr] = currColor;
        for (int& i : adj[curr]) {
            if (colors[i] == colors[curr])
                return false;

            if (colors[i] == -1)
                if (func(adj, i, colors, 1 - currColor) == false)
                    return false;
        }
        return true;
    }
    int maxEach(unordered_map<int, vector<int>>& adj, int curr,
                vector<bool>& visited, vector<int>& levels) {
        int maxGrp = levels[curr];
        visited[curr] = true;
        for (int& i : adj[curr])
            if (!visited[i])
                maxGrp = max(maxGrp, maxEach(adj, i, visited, levels));

        return maxGrp;
    }
    int BFS(unordered_map<int, vector<int>>& adj, int currNode, int n) {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(currNode);
        visited[currNode] = true;
        int count = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                for (int& i : adj[curr]) {
                    if (visited[i])
                        continue;
                    q.push(i);
                    visited[i] = true;
                }
            }
            count++;
        }
        return count - 1;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++)
            if (colors[i] == -1)
                if (func(adj, i, colors, 1) == false)
                    return -1;

        vector<int> levels(n, 0);
        for (int i = 0; i < n; i++)
            levels[i] = BFS(adj, i, n);

        int maxGroup = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
            if (!visited[i])
                maxGroup += maxEach(adj, i, visited, levels);

        return maxGroup;
    }
};
