class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>>> CRFood;
    unordered_map<string, string> fC;
    unordered_map<string, int> fR;

    FoodRatings(vector<string>& foods, vector<string>& cuisines,
                vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            CRFood[cuisines[i]].insert({-ratings[i], foods[i]});
            fC[foods[i]] = cuisines[i];
            fR[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        CRFood[fC[food]].erase({-fR[food], food});
        CRFood[fC[food]].insert({-newRating, food});
        fR[food] = newRating;
    }

    string highestRated(string cuisine) {
        return begin(CRFood[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
