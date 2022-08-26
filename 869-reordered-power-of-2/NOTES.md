solution -1
***BackTracking***
```
bool power2( string &v){
if( v[0]=='0' ) return false;
int n = stoi(v);
return (n&(n-1))==0;
}
bool solve( string v, int ind){
if( ind == v.size()){
return power2(v);
}
for(int i = ind ; i<v.size(); i++){
swap(v[i], v[ind]);
if( solve( v, ind+1)) return true;
swap(v[i], v[ind]);
}
return false;
}
bool reorderedPowerOf2(int n) {
if( (n&(n-1))==0) return true;
string s = to_string(n);
return solve( s, 0);
}
```
​
Solution -2
​