class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;
        vector<int> candiesR(ratings.size(), 1);
        vector<int> candiesL(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candiesL[i] = max(candiesL[i], candiesL[i - 1] + 1);
            }
        }
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candiesR[i] = max(candiesR[i], candiesR[i + 1] + 1);
            }
        }
        for (int i = 0; i < candiesR.size(); ++i)
            ans += max(candiesR[i], candiesL[i]);
        return ans;
    }
};
