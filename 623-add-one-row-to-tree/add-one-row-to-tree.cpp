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
    void solve(TreeNode* root, int val, int depth, int curr){
        if(root==NULL) return ;
        if(curr==depth){
            TreeNode* l= new TreeNode(val);
              TreeNode* r= new TreeNode(val);

              l->left= root->left;
              r->right=root->right;
              root->left=l;
              root->right=r;
              return;

        }

        solve(root->left , val , depth , curr+1);
          solve(root->right , val , depth , curr+1);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
          if(depth==1){
             TreeNode* l= new TreeNode(val);
             l->left=root;
             return l;
          }
         depth--;
          solve(root , val , depth , 1);
          return root;
    }
};