class Solution {
public:
    int n;
    pair<int, int> getCd(int s) {
        int row = n - 1 - (s - 1) / n;
        int col = (s - 1) % n;
        if ((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0))
            col = n - 1 - col;
        return make_pair(row, col);
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int steps = 0;
        queue<int> q;
        vector<vector<bool>> visited(board.size(),
                                     vector<bool>(board.size(), false));
        visited[board.size() - 1][0] = true;
        q.push(1);
        vector<bool> seen(n * n + 1, false);
        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                int x = q.front();
                q.pop();
                if (x == n * n)
                    return steps;
                for (int k = 1; k <= 6; k++) {
                    if (x + k > n * n)
                        break;
                    pair<int, int> cd = getCd(x + k);
                    int r = cd.first;
                    int c = cd.second;
                    if (visited[r][c] == true)
                        continue;
                    visited[r][c] = true;
                    if (board[r][c] == -1)
                        q.push(k + x);
                    else
                        q.push(board[r][c]);
                }
            }
            steps++;
        }
        return -1;
    }
};
