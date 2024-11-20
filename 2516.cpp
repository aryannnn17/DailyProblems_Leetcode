class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count = {0, 0, 0};
        int n = s.length(), left = 0;
        while (left < n &&
               (count.at(0) < k || count.at(1) < k || count.at(2) < k)) {
            count.at(s.at(left) - 'a')++;
            left++;
        }
        if (count.at(0) < k || count.at(1) < k || count.at(2) < k)
            return -1;
        int shortest = left, right = n - 1;
        left -= 1;
        while (left >= 0) {
            count.at(s.at(left) - 'a')--;
            left--;
            while (left <= right &&
                   (count.at(0) < k || count.at(1) < k || count.at(2) < k)) {
                count.at(s.at(right) - 'a')++;
                right--;
            }
            shortest = min(shortest, n - (right - left));
        }
        return shortest;
    }
};
