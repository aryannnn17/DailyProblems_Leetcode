class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long> vec(skill.size(), 0); 

        for (int j = 0; j < mana.size(); ++j) {
            vec[0] += 1LL * mana[j] * skill[0];

            for (int i = 1; i < skill.size(); ++i)
                vec[i] = max(vec[i], vec[i - 1]) + 1LL * mana[j] * skill[i];

            for (int i = skill.size() - 1; i > 0; --i)
                vec[i - 1] = vec[i] - 1LL * mana[j] * skill[i];
        }
        return vec[skill.size()-1];
    }
};

