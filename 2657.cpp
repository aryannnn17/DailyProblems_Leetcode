class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> freq(A.size() + 1, 0);
        int count = 0;
        vector<int> res(A.size());
        for (int i = 0; i < A.size(); ++i) {
            freq[A[i]]++;
            if (freq[A[i]] == 2)
                count++;
            freq[B[i]]++;
            if (freq[B[i]] == 2)
                count++;
            res[i] = count;
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
//         unordered_map<int, int> mp1;
//         unordered_map<int, int> mp2;
//         int count = 0;
//         vector<int> ans(A.size(), 0);
//         for (int i = 0; i < A.size(); ++i) {
//             mp1[A[i]]++;
//             mp2[B[i]]++;
//             if (A[i] == B[i])
//                 ans[i]++;
//             else {
//                 if (mp1.contains(B[i]) && mp1[B[i]] == 1)
//                     ans[i]++;
//                 if (mp2.contains(A[i]) && mp2[A[i]] == 1)
//                     ans[i]++;
//             }
//             ans[i] += count;
//             count = ans[i];
//         }
//         return ans;
//     }
// };
