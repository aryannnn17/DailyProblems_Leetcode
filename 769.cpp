class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int count = 0, num = 0;
        for (int i = 0; i < arr.size(); i++) {
            num = max(num, arr.at(i));
            if (num == i)
                count++;
        }
        return count;
    }
};
