class Solution {
public:
    bool isPossible(vector<int>& ranks, long mid, int cars) {
        long carsFixed = 0;
        for (int i = 0; i < ranks.size(); i++) {
            carsFixed += sqrt(mid / ranks[i]); 
        }
        return carsFixed >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long l = 1;
        int maxR = *max_element(begin(ranks), end(ranks));
        long  r = 1LL * maxR * cars * cars;
        long time = -1;
        while (l <= r) { 
            long mid = l + (r - l) / 2;
            if (isPossible(ranks, mid, cars)) { 
                time = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return time;
    }
};
