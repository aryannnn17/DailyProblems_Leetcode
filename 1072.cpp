class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> freq;
        for (auto row : matrix) {
            int first = row[0];
            string curr;
            for (int ele : row) {
                if (ele == first)
                    curr.push_back('0');
                else
                    curr.push_back('1');
            }
            freq[curr]++;
        }
        int ans = 0;
        for (auto& [string, freq] : freq)
            ans = max(ans, freq);

        return ans;
    }
};
