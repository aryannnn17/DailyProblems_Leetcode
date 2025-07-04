class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (k == 1)
            return 'a';

        int op;
        long long len = 1;
        long long newK;
        for (int i = 0; i < operations.size(); i++) {
            len *= 2;
            if (len >= k) {
                op = operations[i];
                newK = k - len / 2;
                break;
            }
        }
        char ans = kthCharacter(newK, operations);
        if (op == 0)
            return ans;
        if (ans == 'z')
            return 'a';
        return ans + 1;
    }
};

// ------------ TLE --------------
// class Solution {
// public:
//     char kthCharacter(long long k, vector<int>& operations) {
//         string ans = "a";
//         int i = 0;
//         while (ans.length() < k) {
//             if (operations[i] == 0)
//                 ans.append(ans);
//             else {
//                 string s = "";
//                 for (char c : ans) {
//                     if (c == 'z')
//                         s.push_back('a');
//                     else
//                         s.push_back(c + 1);
//                 }
//                 ans.append(s);
//             }
//             i++;
//         }
//         return ans[k - 1];
//     }
// };
