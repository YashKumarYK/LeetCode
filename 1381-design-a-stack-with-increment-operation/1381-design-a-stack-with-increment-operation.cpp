class CustomStack {
public:
    vector<int> v;
    int last=1;
    int maxi=0;
    CustomStack(int maxSize) {
        maxi = maxSize;
    }
    
    void push(int x) {
        if( v.size()== maxi){
            return;
        }
        v.push_back(x);
    }
    
    int pop() {
        if( v.size()==0) return -1;
        
        int el = v.back();
        v.pop_back();
        return el;
    }
    
    void increment(int k, int val) {
        int n = v.size();
        
        for( int i=0; i<min(k, n); ++i){
            v[i]+= val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */