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
      void solve(TreeNode* root , int level){
              if(root == NULL) return ;
              if(root->left== NULL && root->right == NULL) {
                mp[level]+=root->val;
              }
              solve(root->left , level+1);
              solve(root->right , level+1);
      }
    int deepestLeavesSum(TreeNode* root) {
        mp.clear();
        solve(root,0);
        int lev=-1, ans=0;
        for(auto it : mp){
            if(it.first > lev){
                lev=it.first;
                ans=it.second;
            }
        }
        return ans;
    }
};