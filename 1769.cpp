//-----< BRUTE FORCE { T.C. - O(n^2) } >---------

// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//         vector<int> ans(boxes.length(), 0);
//         for (int i = 0; i < boxes.length(); ++i) {
//             for (int j = 0; j < boxes.length(); ++j) {
//                 if (boxes[j] == '1')
//                     ans[i] += abs(i - j);
//             }
//         }
//         return ans;
//     }
// };


//------- T.C. - O(N) --------------
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(), 0);
        int cumValue = 0, cumValueSum = 0;
        for (int i = 0; i < boxes.size(); i++) {
            ans[i] = cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }
        cumValue = 0, cumValueSum = 0;
        for (int i = boxes.size() - 1; i >= 0; i--) {
            ans[i] += cumValueSum;
            cumValue += boxes[i] == '0' ? 0 : 1;
            cumValueSum += cumValue;
        }
        return ans;
    }
};
