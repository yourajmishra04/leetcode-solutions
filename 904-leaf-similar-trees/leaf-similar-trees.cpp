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
  vector<int>v;

   void solve(TreeNode* root){
          if(root->left == NULL && root->right==NULL) {
            v.push_back(root->val);
            return;
          }
          if(root->left!=NULL) solve(root->left);
          if(root->right!=NULL) solve(root->right);
   }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        v.clear();
        solve(root1);
        vector<int>vv=v;
         v.clear();
        solve(root2);
        return (vv==v);

    }
};