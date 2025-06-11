class Solution {
public:
    int maxDifference(string s) {
        int maxOdd = 0;
        int minEven = s.length() + 1;
        vector<int> vec(26);
        for (char& c : s)
            vec[c - 'a']++;
        sort(vec.begin(), vec.end());
        for (int i = 25; i >= 0; i--) {
            if (vec[i] == 0)
                break;
            if (vec[i] % 2 == 0)
                minEven = min(minEven, vec[i]);
            else
                maxOdd = max(maxOdd, vec[i]);
        }
        return maxOdd - minEven;
    }
};
