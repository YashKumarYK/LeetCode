// { Driver Code Starts
// C++ program to find minimum swaps
// required to group all 1's together
#include <bits/stdc++.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n) ;


// Driver Code
int main() {
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << minSwaps(a, n)<<endl;
    
    }

    return 0;
}
// } Driver Code Ends


int minSwaps(int arr[], int n) {
    
    if(n==1 && arr[0]=='0') return -1;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(arr[i]==1){
            cnt++;
        }
    }
    //sliding window
    int i=0, j=0;
    int sum =0;
    int mini = INT_MAX;
    while( j<n){
        sum+= arr[j];
        
        if( j-i+1==cnt){
            mini = min( mini , cnt-sum);
            
            sum-= arr[i];
            i++;
        }
        j++;
    }
    return mini==INT_MAX? -1:mini;
}