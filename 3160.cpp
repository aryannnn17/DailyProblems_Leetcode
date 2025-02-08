class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> color(100,0);
        vector<int> ball(100,0);
        vector<int> ans;
        int count =0;
        for (int i = 0; i < queries.size(); ++i) {
            if (ball[queries[i][0]] == 0 && color[queries[i][1]] == 0)
                count++;
            ball[queries[i][0]]++;
            color[queries[i][1]]++;
            ans.push_back(count);
        }
        return ans;
    }
};
