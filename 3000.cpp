class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        vector<long> diag;
        long maxD = 0;
        long area = 0;
        for (int i = 0; i < dimensions.size(); ++i)
            diag.push_back(pow(dimensions[i][0], 2) + pow(dimensions[i][1], 2));
        maxD = *max_element(diag.begin(), diag.end());
        for (int i = 0; i < dimensions.size(); ++i)
            if (maxD == diag[i] && area < dimensions[i][0] * dimensions[i][1])
                area = dimensions[i][0] * dimensions[i][1];
        return area;
    }
};
