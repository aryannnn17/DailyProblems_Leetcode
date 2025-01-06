class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.size() + 1, 0);
        string res;
        for (auto& i : shifts) {
            if (i[2] == 1) {
                diff[i[0]]++;
                diff[i[1] + 1]--;
            } else {
                diff[i[0]]--;
                diff[i[1] + 1]++;
            }
        }
        for (int i = 0; i < s.size(); ++i)
            diff[i + 1] += diff[i];

        for (int i = 0; i < s.size(); ++i) {
            int count = diff[i] % 26;
            if (count < 0)
                count += 26;
            char c = char((s[i] - 'a' + count) % 26 + 97);
            res.push_back(c);
        }
        return res;
    }
};
