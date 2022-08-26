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
**Solution -2 ( optimal - 3 ms)**
***sorting and comparing***
```
bool reorderedPowerOf2(int n) {
string s = to_string(n);
sort( s.begin(), s.end());
for(int i=0; i<31;++i){
string s1 = to_string( (int)pow(2,i));
sort( s1.begin(), s1.end());
if( s1==s) return true;
}
return false;
}
```
​