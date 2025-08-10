class Solution {
public:
    vector<pair<int, int>> serves{{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    vector<vector<double>> t;

    double solve(double A, double B) {
        if (A <= 0 && B <= 0)
            return 0.5;

        if (A <= 0)
            return 1.0;
        if (B <= 0)
            return 0.0;

        if (t[A][B] != -1.0)
            return t[A][B];

        double prob = 0.0;
        for (auto& p : serves)
            prob += 0.25 * solve(A - p.first, B - p.second);

        return t[A][B] = prob;
    }

    double soupServings(int n) {
        if (n >= 5000)
            return 1.0;
        t.resize(n + 1, vector<double>(n + 1, -1.0));
        return solve(n, n);
    }
};
