class Solution {
public:
    bool isSet(int& num, int bit) { return num & (1 << bit); }
    bool setBit(int& num, int bit) { return num |= (1 << bit); }
    bool unsetBit(int& num, int bit) { return num &= ~(1 << bit); }
    int minimizeXor(int num1, int num2) {

        int SetBitCount = __builtin_popcount(num2);
        int currSetBitCount = __builtin_popcount(num1);
        int bit = 0;
        if (currSetBitCount < SetBitCount) {
            while (currSetBitCount < SetBitCount) {
                if (!isSet(num1, bit)) {
                    setBit(num1, bit);
                    currSetBitCount++;
                }
                bit++;
            }
        } else if (currSetBitCount > SetBitCount) {
            while (currSetBitCount > SetBitCount) {
                if (isSet(num1, bit)) {
                    unsetBit(num1, bit);
                    currSetBitCount--;
                }
                bit++;
            }
        }
        return num1;
    }
};
