class Solution {
public:
    string compressedString(string word) {
        int count = 1;
        string ans = "";
        for (int i = 0; i < word.length() - 1; i++) {
            if (word.at(i) == word.at(i + 1))
                count++;
            else {
                ans += to_string(count) + word.at(i);
                count = 1;
            }
            if (count > 9) {
                ans += to_string(count - 1) + word.at(i);
                count = 1;
            }
        }
        ans += to_string(count) + word.at(word.length() - 1);
        return ans;
    }
};
