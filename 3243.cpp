class Solution {
    int shortestPath(vector<vector<int>>& adj, int n) {
        queue<int> q;
        q.push(0);
        vector<bool> visited(n);
        visited.at(0) = true;
        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1)
                    return dist;

                for (int ad : adj[curr]) {
                    if (!visited.at(ad)) {
                        visited.at(ad) = true;
                        q.push(ad);
                    }
                }
            }
            dist++;
        }
        return dist;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n,vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; ++i)
            adj.at(i).push_back(i + 1);

        vector<int> ans;
        for (auto& query : queries) {
            adj[query[0]].push_back(query[1]);
            ans.push_back(shortestPath(adj, n));
        }
        return ans;
    }
};
