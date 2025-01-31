class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int DFS(vector<vector<int>>& grid, int i, int j, int& id) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
            return 0;
        grid[i][j] = id;
        int count = 1;
        for (vector<int>& dir : directions)
            count += DFS(grid, i + dir[0], j + dir[1], id);
        return count;
    }

    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        unordered_map<int, int> mp;
        int id = 2;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    int size = DFS(grid, i, j, id);
                    maxArea = max(maxArea, size);
                    mp[id] = size;
                    id++;
                }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    for (vector<int>& dir : directions)
                        if (i + dir[0] >= 0 && i + dir[0] < m &&
                            j + dir[1] >= 0 && j + dir[1] < n &&
                            grid[i + dir[0]][j + dir[1]] != 0)
                            st.insert(grid[i + dir[0]][j + dir[1]]);

                    int sum = 1;
                    for (const int& s : st)
                        sum += mp[s];

                    maxArea = max(maxArea, sum);
                }
            }

        return maxArea;
    }
};
