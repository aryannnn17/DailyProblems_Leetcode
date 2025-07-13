class Solution {
public:
    typedef pair<long long, int> P;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings));
        vector<int> roomCnt(n, 0);
        priority_queue<P, vector<P>, greater<P>> usedRooms;
        priority_queue<int, vector<int>, greater<int>> unusedRooms;

        for (int i = 0; i < n; i++)
            unusedRooms.push(i);

        for (vector<int>& m: meetings) {
            int start = m[0];
            int end = m[1];

            while (!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }

            if (!unusedRooms.empty()) {
                int j = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, j});
                roomCnt[j]++;
            } else {
                int j = usedRooms.top().second;
                long long T = usedRooms.top().first;
                usedRooms.pop();
                usedRooms.push({T + (end - start), j});
                roomCnt[j]++;
            }
        }
        int ans = -1;
        int maxUse = 0;
        for (int i = 0; i < n; i++) {
            if (roomCnt[i] > maxUse) {
                maxUse = roomCnt[i];
                ans = i;
            }
        }
        return ans;
    }
};
