class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> nums;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
                if (grid[0][0] % x != grid[i][j] % x)
                    return -1;
            }
        }
        nth_element(begin(nums), begin(nums) + nums.size() / 2, end(nums));
        int cnt = 0;
        for (int& i : nums)
            cnt += abs(nums[nums.size() / 2] - i) / x;

        return cnt;
    }
};
