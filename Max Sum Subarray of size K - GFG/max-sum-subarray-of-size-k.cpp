// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        int sum =0;
        int maxsum=0;
        //first window
        for( int i=0; i<K; i++){
            sum= sum+ Arr[i];
        }
        maxsum= sum;
        int s =0;
        int e=K;
        while( e < N){
            sum = sum-Arr[s++]+ Arr[e++];
            maxsum = max( sum, maxsum);
        }
        return maxsum;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends