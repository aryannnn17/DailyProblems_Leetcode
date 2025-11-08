class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0)
            return 0;
        
        vector<long long> vec(32, 0);
        vec[0] = 1;
        for(int i = 1; i <= 31; i++) 
            vec[i] = 2*vec[i-1] + 1;
        
        int ans = 0;
        int s  = 1;
        
        for(int i = 30; i >= 0; i--) {
            int ith_bit = ((1 << i) & n);
            if(ith_bit == 0) 
                continue;
            
            if(s > 0)
                ans += vec[i];
            else
                ans -= vec[i];
            
            s *= -1; 
        }
        return ans;
    }
};
