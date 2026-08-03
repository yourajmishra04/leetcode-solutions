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
     map<int,int>mp;
     void solve(TreeNode* root){
        if(root==NULL) return;
        mp[root->val]++;
        solve(root->left);
        solve(root->right);
     }
    bool isUnivalTree(TreeNode* root) {
        mp.clear();
        solve(root);
        return (mp.size()<2);
    }
};