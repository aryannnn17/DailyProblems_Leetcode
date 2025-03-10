class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = blocks.length();
        for (int i = 0; i <= blocks.length() - k; ++i) {
            int b = 0, w = 0, j = i;
            while (b < k) {
                if (blocks[j] == 'W')
                    w++;
                b++;
                j++;
            }
            ans = min(w, ans);
        }
        return ans;
    }
};
