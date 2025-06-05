class Solution {
public:
    char dfs(unordered_map<char, vector<char>>& adj, char curr,
             vector<int>& visited) {
        visited[curr - 'a'] = 1;

        for (char& v : adj[curr]) {
            if (visited[v - 'a'] == 0)
                curr = min(curr, dfs(adj, v, visited));
        }
        return curr;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {

        unordered_map<char, vector<char>> adj;
        for (int i = 0; i < s1.length(); i++) {
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }

        string s;
        for (int i = 0; i < baseStr.length(); i++) {

            vector<int> visited(26, 0);
            s.push_back(dfs(adj, baseStr[i], visited));
        }
        return s;
    }
};
