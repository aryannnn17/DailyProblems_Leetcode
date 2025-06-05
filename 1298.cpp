class Solution {
public:
    int dfs(int box, vector<int>& status, vector<int>& candies,
            vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,
            unordered_set<int>& visited, unordered_set<int>& found) {

        if (visited.count(box))
            return 0;

        if (status[box] == 0) {
            found.insert(box);
            return 0;
        }

        visited.insert(box);
        int cnt = candies[box];

        for (int& insideBox : containedBoxes[box]) {
            cnt += dfs(insideBox, status, candies, keys, containedBoxes,
                       visited, found);
        }

        for (int& boxKey : keys[box]) {
            status[boxKey] = 1;
            if (found.count(boxKey)) {
                cnt += dfs(boxKey, status, candies, keys, containedBoxes,
                           visited, found);
            }
        }

        return cnt;
    }

    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {

        int cnt = 0;
        unordered_set<int> visited;
        unordered_set<int> found;

        for (int& box : initialBoxes) {
            cnt +=
                dfs(box, status, candies, keys, containedBoxes, visited, found);
        }

        return cnt;
    }
};
