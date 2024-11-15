class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        while (right > 0 && arr.at(right) >= arr.at(right - 1))
            right--;

        int shortest = right;
        while (left < right) {
            while (right < arr.size() && arr.at(left) > arr.at(right))
                right++;

            shortest = min(shortest, right - 1 - left);
            left++;
            if (arr.at(left) < arr.at(left - 1))
                break;
        }
        return shortest;
    }
};
