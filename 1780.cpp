// class Solution {
// public:
//     bool checkPowersOfThree(int n) {

//         for (int i = 16; i >= 0; i--)
//             if (pow(3, i) <= n)
//                 n -= pow(3, i);

//         return (n == 0) ? 1 : 0;
//     }
// };

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n > 0) {
            if (n % 3 == 2) {
                return false;
            }
            n /= 3;
        }
        return true;
    }
};
