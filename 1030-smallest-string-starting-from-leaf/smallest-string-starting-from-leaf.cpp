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
  string ans="";

  void solve(TreeNode* root , string path){
    if(root==NULL) return;
    path+='a'+root->val;

    if(root->left==NULL && root->right==NULL){
        reverse(path.begin(),path.end());
        if(ans=="" || ans>path) ans=path;
        return;
    }

    solve(root->left,path);
    solve(root->right,path);


  }

    string smallestFromLeaf(TreeNode* root) {
        ans="";
        solve(root,"");
        return ans;
    }
};