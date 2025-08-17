class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> P(n + 1, 0.0);
        P[0] = 1; 
        double curr = k > 0 ? 1 : 0;
        for (int i = 1; i <= n; i++) {
            P[i] = curr / maxPts;
            if (i < k) 
                curr += P[i];
            if (i - maxPts >= 0 && i - maxPts < k) 
                curr -= P[i - maxPts];
        }
        return accumulate(P.begin() + k, P.end(), 0.0);
    }
};
