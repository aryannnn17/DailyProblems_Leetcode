class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxNum = INT_MIN;
        int ans = 0, n = *max_element(candidates.begin(), candidates.end());
        while (n) {
            int count = 0;
            for (int i = 0; i < candidates.size(); i++) {
                if ((candidates.at(i) & 1)) {
                    count++;
                }
                candidates.at(i) = candidates.at(i) >> 1;
            }
            ans = max(ans, count);
            n = n >> 1;
        }
        return ans;
    }
};
