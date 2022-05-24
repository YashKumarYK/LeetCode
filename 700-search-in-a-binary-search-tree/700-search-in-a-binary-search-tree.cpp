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
    //recursive
    TreeNode* searchBST(TreeNode* root, int val) {
        if( root==NULL ){
            return NULL;
        }
        else if( root->val == val){
            return root;
        }
        
        else if(val> root->val){
            return searchBST(root->right, val);
        }
        else{
            return searchBST(root->left, val);
        }
        
    }
    
    //iteratively
//     TreeNode* searchBST(TreeNode* root, int val) {
//         while( root!=NULL && root->val != val){
//             if ( root->val < val) root = root->right;
//             else if( root->val > val) root= root->left;
//         }
//         return root;
        
//     }
    
};