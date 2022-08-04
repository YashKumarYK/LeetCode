string s;
for( int i=1; i<n+1; i++) s.push_back( i+'0');
set<string> s1;
permut( s, 0, s1);
for( auto i: s1){
if( k==1){
return i;
}
--k;
}
return "";
}
```
​
***Optimal Approach (  RECURSIVE)***
```
void solve( int fact, vector<int> & v, int k, string &s){
if( v.size()==0){
return ;
}
s = s+ to_string(v[k/fact]);
v.erase(v.begin() + k/fact);
if( v.size()!=0)
solve( fact/v.size(), v, k%fact, s);
}
string getPermutation(int n, int k) {
//calculating the factorial of n-1 numbers and making and array of numbers 1->n
int fact =1;
vector<int> v;
for( int i=1; i<n;i++){
fact *= i;
v.push_back(i);
}v.push_back(n);
k= k-1; //for 0-based indexing
string s ="";
solve( fact, v, k, s);
return s;
}
```
​
​