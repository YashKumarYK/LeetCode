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
    void solve( TreeNode* root, int targetSum, vector<int> path, int &count){
        //base case
        if( root==NULL)
            return;
        path.push_back(root->val);
        
        
        solve(root->left, targetSum, path, count);
        solve(root->right, targetSum, path,count);
        long int sum =0;
        for( int i= path.size()-1; i>=0; i--){
            sum += path[i];
            if( sum == targetSum){
                count++;
            }
        }
        path.pop_back();

    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int count=0;
        if(root==NULL){
            return count;
        }
        solve(root, targetSum, path, count);
        return count;
    }
};