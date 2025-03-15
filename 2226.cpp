// -----------< TLE > ----------------
// class Solution {
// public:
//     int maximumCandies(vector<int>& candies, long long k) {
//         int candy = 0;
//         int total = 0;
//         for (int i = 0; i < candies.size(); i++) {
//             total += candies[i];
//             candy = max(candy, candies[i]);
//         }

//         if (total < k)
//             return 0;

//         for (int i = candy; i >= 1; i--) {
//             long long count = 0;
//             for (int j = 0; j < candies.size(); j++)
//                 count += candies[j] / i;
//             if (count >= k)
//                 return i;
//         }
//         return 0;
//     }
// };

class Solution {
public:
    bool canDistr(vector<int>& candies, int mid, long long k) {
        for (int i = 0; i < candies.size(); i++) {
            k -= candies[i] / mid;
            if (k <= 0)
                return true;
        }
        return k <= 0;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int candy = 0;
        long long total = 0;
        for (int i = 0; i < candies.size(); i++) {
            total += candies[i];
            candy = max(candy, candies[i]);
        }

        if (total < k)
            return 0;

        int l = 1;
        int r = candy;
        int result = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canDistr(candies, mid, k)) {
                result = mid;
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return result;
    }
};
