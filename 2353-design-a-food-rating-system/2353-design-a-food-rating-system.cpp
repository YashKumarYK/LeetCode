class comparator{
public:
    bool operator()( pair<int, string> &a, pair<int, string> &b){
        if( a.first == b.first){
            return a.second>b.second;
        }
        return a.first<b.first; 
    }
};

class FoodRatings {
public:
    
    unordered_map< string , priority_queue<pair<int,string>, vector<pair<int, string>>, comparator > > mp;
    unordered_map<string, string> mpcuis;
    unordered_map<string, int> mprate;
    FoodRatings(vector<string>& food, vector<string>& cuisine, vector<int>& rating) {
        
        for( int i=0; i<food.size(); i++){    
            mp[cuisine[i]].push( {rating[i], food[i]});
            
            mpcuis[food[i]] = cuisine[i];
            
            mprate[food[i]] = rating[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        
        mprate[food] = newRating;
        
        string cousine = mpcuis[food];
        
        mp[cousine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        // while(1){
        //     auto it= mp[cuisine].top();
        //     if( it.first == mprate[it.second]) return it.second;
        //      else{
        //         mp[cuisine].pop();
        //     }
        // }
        // return "";
        while(mp[cuisine].top().first != mprate[mp[cuisine].top().second]){
            mp[cuisine].pop();
        }
        return mp[cuisine].top().second;
    }
    
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */