class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> v; 
        v.push_back(startTime[0]);
        for(int i = 1; i < startTime.size(); i++) 
            v.push_back(startTime[i] - endTime[i-1]);
        v.push_back(eventTime - endTime[endTime.size()-1]);

        int i = 0;
        int j = 0;
        int maxSum = 0;
        int currSum = 0;
        while(j < v.size()) {
            currSum += v[j];
            if(i < v.size() && j-i+1 > k+1) {
                currSum -= v[i];
                i++;
            }
            maxSum = max(maxSum, currSum);
            j++;
        }
        return maxSum;
    }
};

