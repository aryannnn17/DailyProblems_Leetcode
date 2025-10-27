class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count = 0;
        int ans = 0;
        for (int i = 0; i < bank.size(); i++) {
            int curr = 0;
            for (char& c : bank[i])
                if (c == '1')
                    curr++;

            ans += (count * curr);
            count = curr == 0 ? count : curr;
        }
        return ans;
    }
};
