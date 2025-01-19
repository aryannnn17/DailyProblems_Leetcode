class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int ans = 0;
        for (int& i : derived)
            ans ^= i;
        
        return (ans == 0) ? 1 : 0;
    }
};
