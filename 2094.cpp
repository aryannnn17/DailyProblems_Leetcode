class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i] != 0) {
                for (int j = 0; j < digits.size(); ++j) {
                    if (i != j) {
                        for (int k = 0; k < digits.size(); ++k) {
                            if (digits[k] % 2 == 0 && j != k && i != k) {
                                int n = (digits[i] * 100) + (digits[j] * 10) +
                                        digits[k];
                                if (find(ans.begin(), ans.end(), n) ==
                                    ans.end())
                                    ans.push_back(n);
                            }
                        }
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
