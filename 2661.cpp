// --------< TLE >---------
// class Solution {
// public:
//     int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
//         vector<int> row(mat.size(),0);
//         vector<int> col(mat[0].size(),0);

//         for (int i = 0; i < arr.size(); ++i) {
//             for (int a = 0; a < mat.size(); ++a) {
//                 if (find(mat[a].begin(), mat[a].end(), arr[i]) !=
//                     mat[a].end()) {
//                     auto it = find(mat[a].begin(), mat[a].end(), arr[i]);
//                     int idx = distance(mat[a].begin(), it);
//                     row[a]++;
//                     col[idx]++;

//                     if (row[a] == mat[a].size() || col[idx] == mat.size())
//                         return i;
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution {
#define pii pair<int, int>
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<pii> temp(m * n + 1);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                temp[mat[i][j]] = make_pair(i, j);

        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for (int i = 0; i < m * n; ++i) {
            pii coordinate = temp[arr[i]];
            row[coordinate.first]++;
            col[coordinate.second]++;
            if (row[coordinate.first] == n or col[coordinate.second] == m)
                return i;
        }
        return 0;
    }
};
