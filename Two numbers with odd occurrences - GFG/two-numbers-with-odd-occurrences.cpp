//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long ans =0;
        for(int i=0; i<N; ++i){
            ans ^=Arr[i];
        }
        long long int a1=0,a2=0,c=0;
        long long int temp = ans;
        while(temp>0){
            if(temp&1) break;
            c++;
            temp=temp>>1;
        }
        for(int i=0; i<N; ++i){
            if((Arr[i]>>c)&1){
                a1^=Arr[i];
            }else{
                a2^=Arr[i];
            }
        }
        if(a1<a2){
            swap(a1, a2);
        }
        return {a1,a2};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends