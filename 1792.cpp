class Solution {
#define pii pair<double, int>

    void heapPush(priority_queue<pii>& maxheap, vector<vector<int>>& classes,
                  int idx) {
        double curr_avg = (double)classes[idx][0] / classes[idx][1];
        double new_avg = ((double)classes[idx][0] + 1) / (classes[idx][1] + 1);
        double possible_increment = new_avg - curr_avg;
        maxheap.push(make_pair(possible_increment, idx));
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pii> maxheap;
        for (int i = 0; i < n; ++i)
            heapPush(maxheap, classes, i);

        while (extraStudents--) {
            pii curr = maxheap.top();
            maxheap.pop();
            int idx = curr.second;
            classes[idx][0]++;
            classes[idx][1]++;

            heapPush(maxheap, classes, idx);
        }
        double avg = 0.0;
        int total_students = 0;
        for (int i = 0; i < n; ++i)
            avg += (double)classes[i][0] / classes[i][1];

        return avg / n;
    }
};
