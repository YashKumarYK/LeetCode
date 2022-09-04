#include<bits/stdc++.h>
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if( root==NULL){
            return ans;
        }
        map<int, map<int, multiset<int>>> mp;
        queue<pair< TreeNode* , pair<int, int>>> q;
        q.push( {root, {0,0}});
        
        while(!q.empty()){
            pair<TreeNode*, pair<int, int>> front= q.front();
            q.pop();
            TreeNode* frontNode = front.first;
            int hd = front.second.first;
            int lvl = front.second.second;
            
            mp[hd][lvl].insert(frontNode->val);
            
            if( frontNode->left) q.push({frontNode->left, {hd-1, lvl+1}});
            if(frontNode->right) q.push({frontNode->right, {hd+1,lvl+1}});
        }
        
        for(auto x: mp){
            vector<int> v;
            for(auto y: x.second){
                v.insert( v.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};