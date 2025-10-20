class Solution {
public:
    void rotate(string& s, int b) {
        reverse(begin(s), end(s));
        reverse(begin(s), begin(s) + b);
        reverse(begin(s) + b, end(s));
    }

    void dfs(string curr, int a, int b, unordered_set<string>& visited,
             string& str) {
        if (visited.count(curr))
            return;
        visited.insert(curr);
        if (curr < str)
            str = curr;

        string s = curr;
        for (int i = 1; i < s.size(); i += 2)
            s[i] = ((s[i] - '0' + a) % 10) + '0';
        dfs(s, a, b, visited, str);

        rotate(curr, b);
        dfs(curr, a, b, visited, str);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        string str = s;
        dfs(s, a, b, visited, str);
        return str;
    }
};
