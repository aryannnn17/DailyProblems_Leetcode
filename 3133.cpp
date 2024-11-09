
// ATTEMPT 1 (getting correct answer but not optimized for long long type )

// class Solution {
// public:
//     long long minEnd(int n, int x) {

//         long long ret = x,count =1 ;
//         int i= x;
//         while (i++) {
//             if (count == n) {
//                 return ret;
//             }
//             if (int(i & x) == x) {
//                 ret = i;
//                 count++;
//             }
//         }
//         return ret;
//     }
// };

// ATTEMPT 2 :

class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        vector<int> xB(64, 0), nB(64, 0);
        for (int i = 0; i < 32; i++) {
            xB.at(i) = (x >> i) & 1;
            nB.at(i) = (n >> i) & 1;
        }
        int i = 0, j = 0;
        while (i < 64) {
            if (xB.at(i) == 1) {
                i++;
                continue;
            }
            xB.at(i++) = nB.at(j++);
        }

        long long ans = 0;
        for (int i = 0; i < 64; i++) {
            ans += xB.at(i) * (1ll << i);
        }
        return ans;
    }
};
