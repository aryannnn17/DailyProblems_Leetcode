class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int cnt = 0;
        int start = 0, end = 0;
        for (auto& i : meetings) {
            if (i[0] > end)
                cnt += i[0] - end - 1;
            end = max(end, i[1]);
        }

        if (days > end)
            cnt += days - end;
        return cnt;
    }
};

// ------< Brute Force >-------
// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         vector<bool> v(days + 1, 0);
//         for (int i = 0; i < meetings.size(); ++i)
//             for (int j = meetings[i][0]; j <= meetings[i][1]; ++j)
//                 v[j] = true;

//         int cnt = 0;
//         for (int i : v)
//             if (i == false)
//                 cnt++;
//         return cnt - 1;
//     }
// };
