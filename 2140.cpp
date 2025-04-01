class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        if (questions.size() == 1)
            return questions[0][0];

        vector<long long> t(200001);
        for (int i = questions.size() - 1; i >= 0; i--)
            t[i] = max(questions[i][0] + t[i + questions[i][1] + 1], t[i + 1]);

        return t[0];
    }
};
