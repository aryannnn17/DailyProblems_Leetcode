class Solution {
public:
    int find(vector<int>& tops, vector<int>& bottoms, int val) {

        int top = 0;
        int bottom = 0;
        for (int i = 0; i < tops.size(); i++) {
            if (tops[i] != val && bottoms[i] != val)
                return -1;
            else if (tops[i] != val)
                top++;
            else if (bottoms[i] != val)
                bottom++;
        }

        return min(top, bottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        for (int i = 1; i <= 6; i++) {
            int n = find(tops, bottoms, i);
            if (n != -1)
                ans = min(ans, n);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
