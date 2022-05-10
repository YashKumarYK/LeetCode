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
    int find( int element, vector<int> inorder){
        for(int i=0; i< inorder.size(); i++){
            if( inorder[i] == element) 
                return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int n, int &index, int instart, int inend){
        //base case
        if( inend >= n || instart>inend) 
            return NULL;
        
        //the index element
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        
        int position = find( element, inorder);
        
        root->left = solve( preorder, inorder, n,index, instart, position-1);
        root->right = solve( preorder, inorder, n, index, position+1, inend);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int preorderIndex = 0;
        TreeNode* ans = solve( preorder, inorder, n, preorderIndex, 0, n-1);
        return ans;
    }
};