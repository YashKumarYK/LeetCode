//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int a[],int n)
    {
        int b[n];
        int j=0;
        for( int i=0; i<n; i++){
            if( a[i]>0){
                b[j++] = a[i];
            }
        }
        for( int i=0; i<n; i++){
            if( a[i]<0){
                b[j++] = a[i];
            }
        }
        for( int i=0; i<n; i++){
            
            a[i] = b[i];
        }
        
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends