class TimeMap {
public:
unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        return bSearch(map[key], timestamp);
    }
    
    string bSearch(vector<pair<int, string>>& vec, int time) {
        
        if(vec.size() == 0)
            return "";
        
        int lo = 0;
        int hi = vec.size()-1;
        
        if(time >= vec[hi].first){
            return vec[hi].second;
        }
        if(time < vec[lo].first)
            return "";
        
        while(hi >= lo) {            
            int mid = lo + (hi-lo)/2;
            if(vec[mid].first == time)
                return vec[mid].second;
            else if(vec[mid].first > time) {
                hi = mid - 1;
            } 
            else {
                lo = mid+1;
            }
        }
        return vec[hi].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */