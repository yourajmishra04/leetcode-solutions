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
int ans;

  int solve(TreeNode* root){
           if(root==NULL) return 0 ;

           int lft= solve(root->left);
           int rgt= solve(root->right);

           int tot=lft + rgt +root->val;
           ans=max(ans,tot);

           int 

           mx=max(root->val , root->val+max(lft,rgt));
           ans=max(ans,mx);
           return mx ;
           
  }


    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        solve(root);
        return ans;
    }
};