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
    
    void inorder(TreeNode* root, vector<TreeNode*> &v, vector<int> &ans){
        if( root==NULL) return;
        
        inorder( root->left, v, ans);
        v.push_back(root);
        ans.push_back( root->val);
        inorder(root->right,v,  ans);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> v;
        
        inorder( root,v, ans);
        
        sort(ans.begin(), ans.end());
        
        for(int i=0; i<ans.size(); i++){
            v[i]->val= ans[i];
        }
    
    }
};