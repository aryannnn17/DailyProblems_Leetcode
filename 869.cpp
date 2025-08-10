class Solution {
public:
    vector<int> counter(int n) {
        vector<int> v(10);
        while (n) {
            v[n % 10]++;
            n /= 10;
        }
        return v;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> v = counter(n);
        for (int i = 0; i < 31; i++) {
            int num = (1 << i);
            if (v == counter(num))
                return true;
        }
        return false;
    }
};
