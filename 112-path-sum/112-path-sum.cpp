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
    void solve(TreeNode* root, int targetSum, vector<int> path, vector<int> &v){
        if( root ==NULL){
            return;
        }
        
        path.push_back(root->val);
        
        if( root->left ==NULL && root->right==NULL){
            int sum=0;
            for ( int i=path.size()-1; i>=0; i--){
                sum += path[i];
            }
            v.push_back(sum);
        }
        
       
        
        solve( root->left, targetSum, path, v);
        solve( root ->right, targetSum, path,v);
        
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        //for path
        vector<int> path;
        
        //for sum of path
        vector<int> v;

        if(root==NULL){
            return false;
        }
    
        solve( root, targetSum, path, v);
        for(int i=0; i<v.size(); i++){
            if (v[i]==targetSum){
                return true;
            }
        }
        return false;
    }
};