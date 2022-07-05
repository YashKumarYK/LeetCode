// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* construct( int preorder[], int inorder[], int &ind,int n,
                        int instart, int inend, map<int, int> &mp){
        if( inend>= n || instart> inend){
            return NULL;
        }
        
        int element = preorder[ind++];
        Node* root = new Node( element);
        
        int position = mp[element];
        root->left = construct(preorder, inorder, ind,n, instart, position -1, mp);
        root->right = construct( preorder, inorder, ind,n,  position+1, inend, mp);
        
        return root;
    }
    Node* buildTree(int inorder[],int preorder[], int n)
    {
        
        map<int, int> mp;
        for( int i=0; i<n; i++){
            mp[inorder[i]]= i;
        }
        int preindex =0;
        Node* root = construct( preorder, inorder, preindex,n, 0, n-1, mp);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends