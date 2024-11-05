class Solution {
public:
    int minChanges(string s) {
        int count1s = 0, count0s = 0, minNum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '1') {
                count1s++;
                if (count0s % 2 == 1) {
                    count0s = 0;
                    count1s++;
                    minNum++;
                }
            } else if (s.at(i) == '0') {
                count0s++;
                if (count1s % 2 == 1) {
                    count1s = 0;
                    count0s++;
                    minNum++;
                }
            }
        }
        return minNum;
    }
};
