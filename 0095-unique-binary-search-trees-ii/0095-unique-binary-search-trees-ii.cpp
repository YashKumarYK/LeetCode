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
    vector<TreeNode*> solve(int n,int s, int e){
        if(n == 0) return {NULL};
        if(n ==1){
            TreeNode* temp = new TreeNode(s);
            return {temp};
        }

        vector<TreeNode*> ans;
        for(int i = s;i<=e;i++){
            vector<TreeNode*> left = solve(i-s, s, i-1);
            vector<TreeNode*> right = solve(e-i,i+1, e);
            for(int j =0; j<left.size(); j++){
                for(int k =0; k<right.size(); k++){
                    TreeNode* temp = new TreeNode(i);
                    temp->left = left[j];
                    temp->right = right[k];
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(n, 1, n);
    }
};