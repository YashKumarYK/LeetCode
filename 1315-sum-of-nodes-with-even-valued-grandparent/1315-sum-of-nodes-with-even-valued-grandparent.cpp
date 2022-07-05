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
    int sumEvenGrandparent(TreeNode* root) {
        if( root==NULL) return 0;
        queue<TreeNode*> q;
        map<TreeNode*, TreeNode*> mp, gp;
        mp[root] = NULL;
        gp[root] =NULL;
        q.push( root);
        int sum=0;
        while( !q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if( gp[front]!=NULL && gp[front]->val %2==0 ){
                sum = sum+front->val;
            }

            if( front->left){
                mp[front->left] = front;
                if( mp[front]!= NULL)
                    gp[front->left] = mp[front];
                q.push(front->left);
            }
            if( front->right){
                mp[front->right] = front;
                if (mp[front] != NULL)
                    gp[front->right] = mp[front];
                q.push( front->right);
            }

        }
        return sum;
    }
};