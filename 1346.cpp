class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size() ; j++) {
                if (arr.at(i) == arr.at(j) * 2 || arr.at(j) == arr.at(i) * 2) {
                    return true;
                }
            }
        }
        return false;
    }
};
