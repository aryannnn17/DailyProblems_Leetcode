class Solution {
public:
    int totalMoney(int n) {
        vector<int> day = {1, 2, 3, 4, 5, 6, 7};
        int money = 0;
        for (int i = 0; i < n; i++)
            money += day[i % 7] + (i / 7);

        return money;
    }
};
