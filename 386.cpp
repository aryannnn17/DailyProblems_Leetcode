class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> v;
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            v.push_back(to_string(i));
        }
        sort(v.begin(), v.end());
        for (string s : v)
            ans.push_back(stoi(s));
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> lexicalOrder(int n) {
//         vector<int> result;
//         int curr = 1;

//         for (int i = 0; i < n; ++i) {
//             result.push_back(curr);
//             if (curr * 10 <= n)
//                 curr *= 10;
//             else {
//                 if (curr >= n)
//                     curr /= 10;
//                 curr += 1;
//                 while (curr % 10 == 0)
//                     curr /= 10;
//             }
//         }

//         return result;
//     }
// };
