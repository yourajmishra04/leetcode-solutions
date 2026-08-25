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
   void solve(TreeNode* root , bool flg , int curr){
        if(root==NULL){ ans=max(ans,curr);
        return ;}
      
        

        if(flg==1){
            solve(root->right , 0, curr +1);
             solve(root->left , 1, 1);
        }

     else{
        solve(root->left , 1 , curr+1);
          solve(root->right , 0 , 1);
     }
   }

  
    int longestZigZag(TreeNode* root) {
          if (root == NULL)
            return 0;
        solve(root,0,0);
        solve(root,1,0);
        return ans-1;
    }
};