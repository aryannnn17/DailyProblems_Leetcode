class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        vector<int> v;
        v.push_back(startTime[0]);
        for (int i = 1; i < startTime.size(); i++)
            v.push_back(startTime[i] - endTime[i - 1]);
        v.push_back(eventTime - endTime[endTime.size() - 1]);

        vector<int> right(v.size(), 0);
        vector<int> left(v.size(), 0);
        for (int i = v.size() - 2; i >= 0; i--)
            right[i] = max(right[i + 1], v[i + 1]);

        for (int i = 1; i < v.size(); i++)
            left[i] = max(left[i - 1], v[i - 1]);

        int ans = 0;
        for (int i = 1; i < v.size(); i++) {
            int curr = endTime[i - 1] - startTime[i - 1];
            if (curr <= max(left[i - 1], right[i]))
                ans = max(ans, v[i - 1] + curr + v[i]);

            ans = max(ans, v[i - 1] + v[i]);
        }

        return ans;
    }
};
