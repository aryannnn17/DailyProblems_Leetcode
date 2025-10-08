class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> cnt(spells.size(), 0);
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); ++i) {
            int left = 0, right = potions.size() - 1;
            int idx = potions.size();

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (spells[i] * (long long)potions[mid] >= success) {
                    idx = mid;
                    right = mid - 1;
                } else
                    left = mid + 1;
            }
            cnt[i] = potions.size() - idx;
        }
        return cnt;
    }
};
