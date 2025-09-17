class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans; 
        for(int n : nums) {
            while(!ans.empty()) {
                int prev = ans.back();
                int GCD = gcd(prev, n);
                if(GCD == 1) 
                    break;
                ans.pop_back();
                int LCM = prev / GCD * n;
                n = LCM; 
            }
            ans.push_back(n); 
        }
        return ans;
    }
};
