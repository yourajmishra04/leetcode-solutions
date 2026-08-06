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
   
    int solve(TreeNode* root ){
                if(root==NULL) return 2;

             int l= solve(root->left) ;
               int r= solve(root->right);

                if(l==0 || r==0) {
                    ans++;
                    return 1;


                }

                if(l==1 || r==1) {
                    return 2;
                }

     return 0;

    }
    int minCameraCover(TreeNode* root) {
        int rootState = solve(root);

        if (rootState == 0)
            ans++;
        return ans;
    }
};