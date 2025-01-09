class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(auto s : words)
            if(s.length()>=pref.length() && s.substr(0,pref.length())==pref)
                count++;
        return count;
    }
};
