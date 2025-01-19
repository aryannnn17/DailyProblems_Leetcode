class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2)
            return false;

        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || locked[i] == '0')
                count++;
            else
                count--;
            if (count < 0)
                return false;
        }
        count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0')
                count++;
            else
                count--;
            if (count < 0)
                return false;
        }
        return true;
    }
};
