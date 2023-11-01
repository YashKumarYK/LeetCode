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
    void inorder(TreeNode* &root, map<int, int> &mp){
        if( root ==NULL) return;
        inorder( root->left, mp);
        mp[root->val]++;
        inorder(root->right, mp);
    }
    vector<int> findMode(TreeNode* root) {
        map<int,int>mp;
        inorder( root, mp);
        vector<pair<int, int>> p;
        for( auto i: mp){
            if( i.second>=1){
                p.push_back({i.second, i.first});
            }
        }
        sort(p.begin(), p.end(), greater());
        vector<int> ans;
        ans.push_back(p[0].second);
        int i= 1;
        while(i<p.size() && p[0].first == p[i].first){
            ans.push_back(p[i].second);
            i++;
        }
        return ans;
    }
};