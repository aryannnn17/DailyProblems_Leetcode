class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        long long ans = 0;
        int prev = 0;
        for (int i = 0; i < target.size(); i++) {
            if (abs(target[i]) > abs(prev)) 
                ans += abs(target[i] - prev);
            prev = target[i];
        }
        return ans;
    }
};
