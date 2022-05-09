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
    void bottomleft(TreeNode* root, int lvl, vector<int> &ans){
        if ( root ==NULL){
            return;
        }
        
        if (lvl ==ans.size()){
            ans.push_back(root->val);
        }
        bottomleft(root->left, lvl+1, ans);
        bottomleft(root->right, lvl+1, ans);
    
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
        if (root ==NULL){
            return 0;
        }
        bottomleft(root, 0, ans);
        return ans[ans.size()-1];
        
    }
};