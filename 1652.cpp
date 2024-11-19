class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int sum = 0, len = code.size();
        vector<int> ans;

        for (int i = 0; i < len; i++)
            ans.push_back(0);
        if (k > 0) {
            for (int i = 0; i < len; i++) {
                int n = k, j = i;
                while (n--) {
                    if (j == len - 1)
                        j = -1;

                    ans.at(i) += code.at(j + 1);
                    j++;
                }
            }
        }
        if (k < 0) {
            for (int i = 0; i < len; i++) {
                int n = k, j = i;
                while (n++) {
                    if (j == 0)
                        j = len;

                    ans.at(i) += code.at(j - 1);
                    j--;
                }
            }
        }

        return ans;
    }
};
