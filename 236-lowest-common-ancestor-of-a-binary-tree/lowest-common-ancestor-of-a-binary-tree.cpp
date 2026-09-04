
class Solution {
public:
  TreeNode* fans=NULL;
  int  solve (TreeNode* root, TreeNode* p, TreeNode* q) {
              if(root == NULL) return 0;

              int l = solve(root->left , p , q);
              int r = solve (root->right , p, q );

              int ans = l+r;
              if(root == p || root == q ) ans++;
              if(ans == 2) {
                fans = root;
                return 0;
              }
              return ans;
    }
   
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root , p, q);
        return fans;
    }
};