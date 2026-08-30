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
  vector<int>ele;
    void solve(TreeNode* root){

        if(root==NULL) return;

        solve(root->left);
        ele.push_back(root->val);
        solve(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        ele.clear();
        solve(root);
         TreeNode* fans= new TreeNode(0);
          TreeNode* temp=fans;

         for(int i=0;i<ele.size();i++){

             TreeNode* tt= new TreeNode(ele[i]);
             temp->right=tt;
             temp=tt;

         }
         return fans->right;

    }
};