
class MovieRentingSystem {
public:
    typedef pair<int, int> P;
    unordered_map<int, set<P>> available;
    unordered_map<int, set<P>> moviePrice;
    set<tuple<int, int, int>> rented;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            available[e[1]].insert({e[2], e[0]});
            moviePrice[e[1]].insert({e[0], e[2]});
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        int cnt = 0;
        if (available.count(movie)) {
            for (auto& [_, i] : available[movie]) {
                ans.push_back(i);
                cnt++;
                if (cnt >= 5)
                    break;
            }
        }

        return ans;
    }

    void rent(int shop, int movie) {
        auto it = moviePrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        auto it = moviePrice[movie].lower_bound({shop, INT_MIN});
        int price = it->second;

        available[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;

        for (auto& [price, shop, movie] : rented) {
            ans.push_back({shop, movie});
            cnt++;
            if (cnt >= 5)
                break;
        }

        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
