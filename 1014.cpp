// -----------< APPROCH 1: BRUTE FORCE (TLE) >-------------------

// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int maxDist = INT_MIN;
//         for (int i = 0; i < values.size() - 1; i++) {
//             for (int j = i + 1; j < values.size(); j++) {
//                 maxDist = max(maxDist, values[i] + values[j] + i - j);
//             }
//         }
//         return maxDist;
//     }
// };

// -----------< APPROACH 2 >-----------------

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n1 = values[0],maxVal= 0;
        for (int i = 1; i < values.size(); i++) {
            int n2 = values[i] - i;
            maxVal = max(maxVal, n1 + n2);
            n1 = max(n1, values[i] + i);
        }
        return maxVal;
    }
};
