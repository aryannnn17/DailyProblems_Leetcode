class Solution {
public:
    void build(int i, int l, int r, vector<int>& baskets,
               vector<int>& segTree) {
        if (l == r) {
            segTree[i] = baskets[l];
            return;
        }
        int m = (l + r) / 2;

        build(2 * i + 1, l, m, baskets, segTree);
        build(2 * i + 2, m + 1, r, baskets, segTree);

        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    }

    bool querysegTree(int i, int l, int r, vector<int>& segTree, int val) {
        if (segTree[i] < val)
            return false;
        if (l == r) {
            segTree[i] = -1;
            return true;
        }
        int mid = (l + r) / 2;
        bool a = false;
        if (segTree[2 * i + 1] >= val)
            a = querysegTree(2 * i + 1, l, mid, segTree, val);
        else
            a = querysegTree(2 * i + 2, mid + 1, r, segTree, val);

        segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
        return a;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<int> segTree(4 * n, -1);
        build(0, 0, n - 1, baskets, segTree);

        int cnt = 0;
        for (int& i : fruits)
            if (!querysegTree(0, 0, n - 1, segTree, i))
                cnt++;

        return cnt;
    }
};
