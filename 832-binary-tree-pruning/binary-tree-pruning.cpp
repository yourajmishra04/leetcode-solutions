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
    bool solve(TreeNode* root){
        if(root == NULL) return 0;
        bool ans=1;
        if(root->val==0) ans=0;

       bool lft= solve(root->left);
       bool rght= solve(root->right);

       if(lft==0) root->left=NULL;
       if(rght==0) root->right=NULL;

       return ans || lft || rght;
    }
    TreeNode* pruneTree(TreeNode* root) {
      bool ans=  solve(root);
      if(ans==0) return NULL;
        return root;
    }
};