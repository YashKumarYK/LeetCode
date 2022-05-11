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
    void inorder( TreeNode* root, set<int> &s){
        if( root==NULL){
            return;
        }
        s.insert(root->val);
        if( root->left) inorder(root->left, s);
        if(root->right) inorder(root->right, s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        inorder(root, s);
        // long ans = LONG_MAX;
        // int min = root->val;
        for( auto i:s)
            if( i> root->val && i< LONG_MAX){
                return i;
            }
        return -1;
    }
};