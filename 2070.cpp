class Solution {
public:
    int binSearch(vector<vector<int>>& items, int price) {
        int maxB = 0;
        int left = 0;
        int right = items.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (items[mid][0] <= price) {
                maxB = max(maxB, items[mid][1]);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return maxB;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        for (int i = 1; i < n; ++i) {
            items[i][1] = max(items[i - 1][1], items[i][1]);
        }
        vector<int> res;
        for (int i = 0; i < queries.size(); ++i) {
            int maxB = binSearch(items, queries[i]);
            res.push_back(maxB);
        }
        return res;
    }
};
