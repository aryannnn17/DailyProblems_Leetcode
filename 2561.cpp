class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
        for (int i = 0; i < basket1.size(); ++i) {
            freq[basket1[i]]++;
            freq[basket2[i]]--;
        }
        int minVal = INT_MAX;
        vector<int> v;
        unordered_map<int, int> mp;
        for (auto [val, diff] : freq) {
            if (diff % 2)
                return -1;
            for (int i = 0; i < abs(diff) / 2; ++i)
                v.push_back(val);
            minVal = min(minVal, val);
        }

        sort(v.begin(), v.end());
        long cost = 0;
        for (int i = 0; i < v.size() / 2; ++i)
            cost += min(v[i], 2 * minVal);
        return cost;
    }
};
