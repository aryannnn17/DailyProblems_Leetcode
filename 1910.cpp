class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (true) {
            int idx = s.find(part);
            cout << idx << endl;
            if (idx == -1) {
                break;
            }
            s.erase(idx, part.length());
        }
        return s;
    }
};
