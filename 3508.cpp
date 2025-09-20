class Router {
private:
    int MAX_SIZE;
    unordered_map<string, vector<int>> packet;
    unordered_map<int, vector<int>> DT;
    queue<string> q;

    string makeKey(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" +
               to_string(timestamp);
    }

public:
    Router(int memoryLimit) { MAX_SIZE = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);

        if (packet.find(key) != packet.end())
            return 0;

        if ((int)packet.size() >= MAX_SIZE)
            forwardPacket();

        packet[key] = {source, destination, timestamp};
        q.push(key);
        DT[destination].push_back(timestamp);
        return 1;
    }

    vector<int> forwardPacket() {
        if (packet.empty())
            return {};
        string key = q.front();
        q.pop();

        vector<int> v = packet[key];
        packet.erase(key);
        DT[v[1]].erase(DT[v[1]].begin());
        return v;
    }

    int getCount(int destination, int startTime, int endTime) {
        auto it = DT.find(destination);
        if (it == DT.end() || it->second.empty())
            return 0;

        vector<int>& list = it->second;
        int leftIdx =
            (lower_bound(list.begin(), list.end(), startTime) - list.begin());
        int rightIdx =
            (upper_bound(list.begin(), list.end(), endTime) - list.begin());

        return rightIdx - leftIdx;
    }
};
