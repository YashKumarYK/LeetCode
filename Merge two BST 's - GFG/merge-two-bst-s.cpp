// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



 // } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    vector<int> merge( vector<int> v1, vector<int> v2){
        vector<int> ans( v1.size()+ v2.size());
        int i=0; int j=0; int k=0;
        while( i< v1.size() && j<v2.size()){
            if( v1[i]< v2[j]){
                ans[k++]= v1[i++];
            }
           
            else{
                ans[k++]= v2[j++];
            }
        }
        
        while( i<v1.size()){
            ans[k++] = v1[i++];
        }
        while( j<v2.size()){
            ans[k++] = v2[j++];
        }
        
        return ans;
    }
    void inorder( Node* root, vector<int> &v){
        if( root ==NULL) return;
        if( root->left) inorder(root->left, v);
        v.push_back(root->data);
        if(root->right) inorder(root->right, v);
    }
    
    // Node* buildBST( vector<int> mergeArr, int mini, int maxi, int &index){
    //     if(index> mergeArr.size()) return NULL;
        
    //     if( mergeArr[index]> maxi && mergeArr[index]< mini){
    //         return NULL;
    //     }
    //     Node* root = new Node(mergeArr[index++]);
    //     root->left = buildBST( mergeArr, mini, root->data, index);
    //     root->right = buildBST(mergeArr, root->data, maxi, index);
        
    //     return root;
        
    // }
    vector<int> merge(Node *root1, Node *root2)
    {
      vector<int> v1;
      vector<int> v2;
      inorder(root1, v1);
      inorder(root2, v2);
      
      vector<int> mergeArr = v1[0]<v2[0]? merge(v1, v2): merge(v2,v1) ;
    //   int index =0;
    //   int mini = INT_MIN;
    //   int maxi = INT_MAX;
    //   return buildBST( mergeArr, mini, maxi, index );
    return mergeArr;
      
    }
};

// { Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}  // } Driver Code Ends