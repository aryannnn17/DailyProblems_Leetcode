class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int pairs = 0;
        int p = 0;
        int t = 0;
        while (p < players.size() && t < trainers.size()) {
            if (players[p] <= trainers[t]) {
                pairs++;
                p++;
                t++;
            } else
                t++;
        }
        return pairs;
    }
};
