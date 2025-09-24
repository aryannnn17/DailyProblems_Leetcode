class Solution {
public:
    vector<string> getTokens(string version) {
        stringstream v(version);
        string s = "";
        vector<string> tokens;
        while (getline(v, s, '.')) 
            tokens.push_back(s);
        return tokens;
    }
    int compareVersion(string version1, string version2) {

        vector<string> v1 = getTokens(version1);
        vector<string> v2 = getTokens(version2);
        int i = 0;
        while (i < v1.size() || i < v2.size()) {
            int a = i < v1.size() ? stoi(v1[i]) : 0;
            int b = i < v2.size() ? stoi(v2[i]) : 0;
            if (a > b)
                return 1;
            else if (b > a)
                return -1;
            else
                i++;
        }
        return 0;
    }
};
