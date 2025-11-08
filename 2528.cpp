class Solution {
public:
    bool check(long long mid, vector<long long>& diff, int r, int k, int n) {
        vector<long long> tempDiff = diff;

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += tempDiff[i];
            if (sum < mid) {
                long long need = mid - sum;
                if (need > k)
                    return false;
                k -= need;
                sum += need;
                if (i + 2 * r + 1 < n)
                    tempDiff[i + 2 * r + 1] -= need;
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        vector<long long> diff(n, 0);
        for (int i = 0; i < n; i++) {
            diff[max(0, i - r)] += stations[i];
            if (i + r + 1 < n)
                diff[i + r + 1] -= stations[i];
        }
        long long l = *min_element(begin(stations), end(stations));
        long long u = accumulate(begin(stations), end(stations), 0LL) + k;
        long long ans = 0;
        while (l <= u) {
            long long mid = l + (u - l) / 2;
            if (check(mid, diff, r, k, n)) {
                ans = mid;
                l = mid + 1;
            } else
                u = mid - 1;
        }
        return ans;
    }
};
