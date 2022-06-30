***Brute Force Approach ( TLE)***
```
bool isUgly(int n) {
if(n<=0) return false;
for(int i=2; i<6 &&n; i++){
while( n%i ==0){
n/=i;
}
}
return n==1;
}
int nthUglyNumber(int n) {
if (n<=6) return n;
int i =7;
n = n-6;
int ans =0;
while(n){
if( isUgly(i)){
n--;
if( n==0)
ans =i;
}
i++;
}
return ans;
}
```
​