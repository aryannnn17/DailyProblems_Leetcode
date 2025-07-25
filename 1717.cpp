class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string first = (x > y) ? "ab" : "ba";
        string second = (x > y) ? "ba" : "ab";
        int points = 0;
        stack<char> st;
        
        for (char& c : s) {
            if (!st.empty() && st.top() == first[0] && c == first[1]) {
                st.pop();
                points += max(x, y);
            } else
                st.push(c);
        }

        string rem;
        while (!st.empty()) {
            rem += st.top();
            st.pop();
        }

        for (char& c : rem) {
            if (!st.empty() && st.top() == second[1] && c == second[0]) {
                st.pop();
                points += min(x, y);
            } else
                st.push(c);
        }

        return points;
    }
};
