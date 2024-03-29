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
    void solve(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>> &ans){
        if( root ==NULL){
            return;
        }
        
        path.push_back(root->val);
        
        if( root->left ==NULL && root->right==NULL){
            int sum=0;
            for ( int i=path.size()-1; i>=0; i--){
                sum += path[i];
            }
            if (sum==targetSum){
                ans.push_back(path);
            }
            
        }
        solve( root->left, targetSum, path, ans);
        solve( root ->right, targetSum, path,ans);
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        if( root==NULL){
            return ans;
        }
        solve(root, targetSum, path, ans);
        return ans;
        
    }
};