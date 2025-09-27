class Solution {
public:
    vector<vector<int>> t;
    map<string, int> mp;
    int solve(int row, int col) {
        string key = to_string(row) + "_" + to_string(col);
        if(mp.count(key))
            return mp[key];
        int minPath = t[row][col];
        if(row < t.size()-1) 
            minPath += min(solve(row+1, col), solve(row+1, col+1));
        return mp[key] = minPath;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        t = triangle;
        return solve(0, 0);
    }
};
