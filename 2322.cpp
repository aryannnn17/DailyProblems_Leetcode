class Solution {
public:
    void dfs(int node, int parent, vector<int>& subT, vector<int>& in,
             vector<int>& out, int& T, vector<int>& nums,
             unordered_map<int, vector<int>>& adj) {
        subT[node] = nums[node];
        in[node] = T;
        T++;
        for (int& i : adj[node]) {
            if (i != parent) {
                dfs(i, node, subT, in, out, T, nums, adj);
                subT[node] ^= subT[i];
            }
        }
        out[node] = T;
        T++;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        unordered_map<int, vector<int>> adj;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> subT(n, 0);
        vector<int> in(n, 0);
        vector<int> out(n, 0);
        int T = 0;
        dfs(0, -1, subT, in, out, T, nums, adj);

        int ans = INT_MAX;
        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                int xor1, xor2, xor3;
                if (in[v] >= in[u] && out[v] <= out[u]) {
                    xor1 = subT[v];
                    xor2 = subT[u] ^ subT[v];
                    xor3 = subT[0] ^ xor1 ^ xor2;
                } else if (in[u] >= in[v] && out[u] <= out[v]) {
                    xor1 = subT[u];
                    xor2 = subT[v] ^ subT[u];
                    xor3 = subT[0] ^ xor1 ^ xor2;
                } else {
                    xor1 = subT[u];
                    xor2 = subT[v];
                    xor3 = subT[0] ^ xor1 ^ xor2;
                }
                ans =
                    min(ans, max({xor1, xor2, xor3}) - min({xor1, xor2, xor3}));
            }
        }

        return ans;
    }
};
