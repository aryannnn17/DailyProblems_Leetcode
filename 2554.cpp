class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0, sum = 0, curr = 1;
        while (curr <= n) {
            auto check = find(banned.begin(), banned.end(), curr);
            if (check == banned.end()) {
                sum += curr;
                if (sum > maxSum)
                    return count;
                count++;
            }
            curr++;
        }
        return count;
    }
};
