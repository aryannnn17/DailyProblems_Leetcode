class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int wordCount = 0, j = 0;
        bool check = true;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence.at(i) == ' ') {
                j = 0;
                wordCount++;
                check = true;
            } else if (sentence.at(i) == searchWord.at(j) && check) {
                j++;
                if (j == searchWord.length()) {
                    return wordCount + 1;
                }
            } else {
                check = false;
                j = 0;
            }
        }
        return -1;
    }
};
