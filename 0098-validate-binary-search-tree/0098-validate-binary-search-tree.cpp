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
    bool isBST( TreeNode* root, long minVal, long maxVal){
        if( root == NULL){
            return true;
        }
        if(root->val>=maxVal || root->val<=minVal) return false;

        bool left = isBST(root->left, minVal, root->val);
        bool right = isBST(root->right, root->val, maxVal);
        return left && right;
    }

    bool isValidBST(TreeNode* root) {        
        //approach2 using recursion
        if (root->left ==NULL && root->right==NULL)
            return true;
        bool ans = isBST(root, LONG_MIN, LONG_MAX);
        return ans;
    }
};