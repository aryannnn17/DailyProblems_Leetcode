class Solution {
public:
    int M = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> pow;
        vector<int> ans;
        for (int i = 0; i < 32; i++)
            if ((n & (1 << i)) != 0)
                pow.push_back(1 << i);

        for (auto& q : queries) {
            long prod = 1;
            for (int i = q[0]; i <= q[1]; i++)
                prod = (prod * pow[i]) % M;
            ans.push_back(prod);
        }
        return ans;
    }
};
