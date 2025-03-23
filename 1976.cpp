class Solution {
public:
    typedef pair<long long, int> P;
    const int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& i : roads) {
            int u = i[0], v = i[1], time = i[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> ans(n, LLONG_MAX);
        vector<int> cnt(n, 0);
        ans[0] = 0;
        cnt[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long cT = pq.top().first;
            int cN = pq.top().second;
            pq.pop();

            for (auto& vec : adj[cN]) {
                int n = vec.first;
                int rT = vec.second;
                if (cT + rT < ans[n]) {
                    ans[n] = cT + rT;
                    cnt[n] = cnt[cN];
                    pq.push({ans[n], n});
                } else if (cT + rT == ans[n]) 
                    cnt[n] = (cnt[n] + cnt[cN]) % M;
                
            }
        }
        return cnt[n - 1];
    }
};
