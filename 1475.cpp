class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices.at(i) >= prices.at(j)) {
                    prices.at(i) -= prices.at(j);
                    break;
                }
            }
        }
        return prices;
    }
};
