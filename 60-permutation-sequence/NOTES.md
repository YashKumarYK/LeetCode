solve( fact, v, k, s);
return s;
}
```
​
***Optimal Approach (Iterative)***
```
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
while( true){
s += to_string( v[ k/fact]);
v.erase( v.begin()+ k/fact);
k= k%fact;
if( v.size()==0) break;
fact /=v.size();
}
return s;
}
```