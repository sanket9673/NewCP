class FoodRatings {
public:
    struct cmp {
        bool operator()(pair<int, string> &p1, pair<int, string> &p2) {
            if (p1.first == p2.first) {
                return p1.second > p2.second ; // smaller value first
            }
            return p1.first < p2.first ; // large value first 
        }
    };
    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, cmp>> mp ;
    unordered_map<string, int> rate ; // stores current food rating
    unordered_map<string, string> cuis ; // [cuisines, food]

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            mp[cuisines[i]].push({ratings[i], foods[i]}) ;
            rate[foods[i]] = ratings[i] ;
            cuis[foods[i]] = cuisines[i] ;
        }
    }
    
    void changeRating(string food, int newRating) {
        rate[food] = newRating ;
        string c = cuis[food] ;
        mp[c].push({newRating, food}) ;
    }
    
    string highestRated(string cuisine) {
        auto &pq = mp[cuisine] ;
        while (true) {
            auto top = pq.top() ;
            if (rate[top.second] == top.first) { // new val map == val in heap
                return top.second ; // return cuisine
            }
            pq.pop() ; // remove outdated
        }
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */