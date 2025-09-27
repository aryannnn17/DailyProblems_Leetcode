class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {

        double maxArea = 0.0;

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {

                    double a = hypot(points[j][0] - points[i][0],
                                     points[j][1] - points[i][1]);
                    double b = hypot(points[j][0] - points[k][0],
                                     points[j][1] - points[k][1]);
                    double c = hypot(points[k][0] - points[i][0],
                                     points[k][1] - points[i][1]);

                    double s = (a + b + c) * 0.5;
                    double heron = sqrt(s * (s - a) * (s - b) * (s - c));
                    double shoelace =
                        0.5 * abs(points[i][0] * (points[j][1] - points[k][1]) +
                                  points[j][0] * (points[k][1] - points[i][1]) +
                                  points[k][0] * (points[i][1] - points[j][1]));

                    maxArea = max({maxArea, heron, shoelace});
                }
            }
        }
        return maxArea;
    }
};
