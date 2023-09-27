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

    int height(TreeNode* root){
        if(root==NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        return max(left, right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        //two choice ->
        //1. current node not be included
        //left
        int left =  diameterOfBinaryTree(root->left);

        //right
        int right = diameterOfBinaryTree(root->right);

        //2. current node included
        int lh = height(root->left);
        int rh = height(root->right);

        int rootdia = lh+rh;

        return max({left, right, rootdia});
    }
};