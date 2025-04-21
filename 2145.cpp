class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int curr = 0;
        int low = 0;
        int high = 0;
        for (int i : differences) {
            curr = curr + i;
            low = min(low, curr);
            high = max(high, curr);
            if ((upper - high) - (lower - low)  <= -1)
                return 0;
        }
        return (upper - high) - (lower - low) + 1;
    }
};
