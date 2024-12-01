class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> nums(n);
        for (auto& edge : edges)
            nums.at(edge.at(1))++;
        int st = 0, champion;
        for (int i = 0; i < n; ++i)
            if (nums.at(i) == 0) {
                champion = i;
                st++;
            }
        return st == 1 ? champion : -1;
    }
};
