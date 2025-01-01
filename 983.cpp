class Solution {
    unordered_map<int, int> ways;
    int solve(vector<int>& days, vector<int>& costs, int pos, int count) {
        if (pos > days.size() - 1)
            return 0;
        if (count >= days[pos])
            return solve(days, costs, pos + 1, count);
        if (ways.count(pos))
            return ways[pos];

        int single = costs[0] + solve(days, costs, pos + 1, days[pos]),
            week = costs[1] + solve(days, costs, pos + 1, days[pos] + 6),
            month = costs[2] + solve(days, costs, pos + 1, days[pos] + 29);
        return ways[pos] = min({single, week, month});
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return min({costs[0] + solve(days, costs, 0, days[0]),
                    costs[1] + solve(days, costs, 0, days[0] + 6),
                    costs[2] + solve(days, costs, 0, days[0] + 29)});
    }
};
