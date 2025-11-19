class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if (bits[bits.size() - 1] == 1)
            return false;
        for (int i = 0; i < bits.size() - 1; i++) {
            if (i == bits.size() - 2 && bits[i] == 1)
                return false;
            if (bits[i] == 1) 
                i++;
            
        }
        return true;
    }
};
