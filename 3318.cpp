class Solution {
public:
    typedef pair<int, int> P;
    int TopXSum(unordered_map<int, int>& mp, int x) {
        priority_queue<P, vector<P>, greater<P>> pq;
        for (auto& it : mp) {
            pq.push({it.second, it.first});
            if (pq.size() > x) 
                pq.pop();
            
        }

        int sum = 0;
        while (!pq.empty()) {
            auto [freq, val] = pq.top();
            pq.pop();
            sum += freq * val;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<int> ans;

        int i = 0;
        int j = 0;

        while (j < n) {
            mp[nums[j]]++;
            if (j - i + 1 == k) {
                ans.push_back(TopXSum(mp, x));
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};
