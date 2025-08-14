class Solution {
public:
    string largestGoodInteger(string num) {
        int a = -1;
        for (int i = 0; i < num.length() - 2; ++i) 
            if (num[i] == num[i + 2] && num[i] == num[i + 1]) 
                a = max(a, num[i] - '0');
            
        
        if (a == -1)
            return "";
        return  string(3, '0' + a);
    }
};
