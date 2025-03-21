class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) { parent[y] = x; }

    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {

        parent.resize(n);
        vector<int> cost(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            cost[i] = -1;
        }

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            int p1 = find(u), p2 = find(v);
            if (p1 != p2) {
                cost[p1] &= cost[p2];
                Union(p1, p2);
            }
            cost[p1] &= w;
        }

        vector<int> res;
        for (auto& q : query) {
            int s = q[0], t = q[1];
            int p1 = find(s), p2 = find(t);
            if (s == t)
                res.push_back(0);
            else if (p1 != p2)
                res.push_back(-1);
            else
                res.push_back(cost[p1]);
        }
        return res;
    }
};
