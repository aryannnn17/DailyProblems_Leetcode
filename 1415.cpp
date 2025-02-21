class Solution {
public:
    void solve(int n, string& curr, vector<string>& ans) {
        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        } 
        for (char i = 'a'; i <= 'c'; i++) {
            if (!curr.empty() && curr.back() == i)
                continue;
            curr.push_back(i);
            solve(n, curr, ans);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> ans;
        solve(n, curr, ans);

        if (ans.size() < k)
            return "";

        return ans[k - 1];
    }
};
