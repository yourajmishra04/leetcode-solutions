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
    int ans=0;
    void solve(TreeNode* root, int level1 , int level2){

        if(root == NULL) return ;

        if(level2 % 2==0) ans+=root->val;
         
         solve(root->left ,  root->val, level1);
          solve(root->right , root->val,level1);

    }
    int sumEvenGrandparent(TreeNode* root) {
        solve(root , 1,1);
        return ans;
    }
};