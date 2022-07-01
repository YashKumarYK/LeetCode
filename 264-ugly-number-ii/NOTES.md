ans =i;
}
i++;
}
return ans;
}
```
​
***Using Set  and Recursion***
```
void solve( set<long long> &s, long long num){
if(num >=INT_MAX) return;
if( s.find(num)!=s.end()) return;
s.insert(num);
solve(s, num*2);
solve(s, num*3);
solve(s, num*5);
}
int nthUglyNumber(int n) {
set<long long> s;
solve( s, 1);
int ans =n;
for( auto i: s){
n--;
if( n==0) ans = i;
}
return ans;
}
```
​
***Using three - pointer and an array/vector - optimal solution***
```
int nthUglyNumber(int n) {
vector<int> ans(n, 0);
ans[0] =1;
int p2=0;
int p3=0;
int p5=0;
for(int i=1;i<n;++i){
int el = min({ans[p2]*2, ans[p3]*3, ans[p5]*5});
ans[i] =el;
if( ans[p2]*2==el) p2++;
if( ans[p3]*3==el) p3++;
if( ans[p5]*5==el) p5++;
}
return ans[n-1];
}
```