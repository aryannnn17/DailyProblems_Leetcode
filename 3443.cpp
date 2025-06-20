class Solution {
public:
    int maxDistance(string s, int k) {
        int dist = 0;
        int east = 0;
        int west = 0;
        int north = 0;
        int south = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'E')
                east++;
            else if (s[i] == 'W')
                west++;
            else if (s[i] == 'N')
                north++;
            else if (s[i] == 'S')
                south++;

            int curr = abs(east - west) + abs(north - south);
            int steps = i + 1;
            int opp = steps - curr;

            int extra = 0;
            if (opp != 0)
                extra = min(2 * k, opp);

            int final = curr + extra;
            dist = max(dist, final);
        }

        return dist;
    }
};
