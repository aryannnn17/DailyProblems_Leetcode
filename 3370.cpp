class Solution {
public:
    int smallestNumber(int n) {
        int b = 0;
        while(n){
            b++;
            n/=2;
        }
        return pow(2,b)-1;
    }
};
