class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(begin(intervals), end(intervals));
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < res.back()[1])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> h;
        vector<vector<int>> v;
        for (auto& i : rectangles) {
            int x1 = i[0];
            int y1 = i[1];
            int x2 = i[2];
            int y2 = i[3];
            h.push_back({x1, x2});
            v.push_back({y1, y2});
        }
        vector<vector<int>> ans1 = merge(h);
        if (ans1.size() >= 3)
            return true;

        vector<vector<int>> ans2 = merge(v);
        return ans2.size() >= 3;
    }
};
