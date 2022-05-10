/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//     int find( int element, vector<int> inorder){
//         for(int i=0; i< inorder.size(); i++){
//             if( inorder[i] == element) 
//                 return i;
//         }
//         return -1;
//     }
    
    //instead of using the forloop many type we can find the position of element simply by using a map
    void createMapping(vector<int>& inorder, map<int, int> &nodeToIndex, int n){
        for(int i=0; i<n; i++){
            nodeToIndex[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int n, int &index, int instart, int inend, map<int, int> &nodeToIndex){
        //base case
        if( inend >= n || instart>inend) 
            return NULL;
        
        //the index element
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        
        // int position = find( element, inorder);
        int position = nodeToIndex[element];
        
        root->left = solve( preorder, inorder, n,index, instart, position-1,nodeToIndex);
        root->right = solve( preorder, inorder, n, index, position+1, inend,  nodeToIndex);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preorderIndex = 0;
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex,n );
        TreeNode* ans = solve( preorder, inorder, n, preorderIndex, 0, n-1, nodeToIndex);
        return ans;
    }
};