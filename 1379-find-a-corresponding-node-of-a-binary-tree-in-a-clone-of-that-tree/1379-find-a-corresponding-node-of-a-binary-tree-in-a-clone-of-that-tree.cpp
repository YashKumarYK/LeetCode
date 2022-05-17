/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    void inorder( TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &ans){
        if (original==NULL)
            return;
        
        inorder(original->left,cloned->left, target, ans);
        if( original == target){
            ans = cloned;
        }
        inorder(original->right, cloned->right, target, ans);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans=NULL;
        inorder(original, cloned, target, ans);
        return ans;
    }
};