// Last updated: 6/11/2026, 11:22:46 AM
struct Cmp{
    bool operator()(const pair<int, string> &a, const pair<int, string> &b) const {
        if(a.first != b.first){
            return a.first>b.first;
        }
        return a.second<b.second;
    }
};

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>, Cmp> > ump;
    unordered_map<string, string> ump2;
    unordered_map<string, int> ump3;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            string cui = cuisines[i];
            string fd = foods[i];
            int rt = ratings[i];
            ump[cui].insert({rt, fd});
            ump2[fd] = cui;
            ump3[fd] = ratings[i];
        }
    }
    
    void changeRating(string food, int nrat) {
        string cui = ump2[food];
        int orat = ump3[food];

        auto &temp = ump[cui];

        auto it = temp.find(make_pair(orat, food));

        temp.erase(it);
        temp.insert({nrat, food});

        ump3[food] = nrat;
    }
    
    string highestRated(string cuisine) {
        return (*ump[cuisine].begin()).second;
    }

};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */