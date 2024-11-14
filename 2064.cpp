class Solution {
public:
    bool canDistribute(vector<int>& quantities, int n, int maxQty) {
        int items = 0;
        for (int q : quantities) {
            items += (q + maxQty - 1) / maxQty;
            if (items > n)
                return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(quantities, n, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
