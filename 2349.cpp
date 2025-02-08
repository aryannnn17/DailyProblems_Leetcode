class NumberContainers {
public:
    unordered_map<int, int> num;
    unordered_map<int, set<int>> idx;

    NumberContainers() {}

    void change(int index, int number) {
        if (num.count(index)) {
            int prevNum = num[index];
            idx[prevNum].erase(index);
            if (idx[prevNum].empty()) {
                idx.erase(prevNum);
            }
        }
        num[index] = number;
        idx[number].insert(index);
    }

    int find(int number) {
        if (idx.count(number)) {
            return *idx[number].begin();
        }
        return -1;
    }
};
