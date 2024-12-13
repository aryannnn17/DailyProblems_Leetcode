class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        while (k--) {
            sort(gifts.begin(), gifts.end());
            gifts.at(gifts.size() - 1) = sqrt(gifts.at(gifts.size() - 1));
        }
        long long ans = 0;
        for (int& i : gifts)
            ans += i;
        return ans;
    }
};
