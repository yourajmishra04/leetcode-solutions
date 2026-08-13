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
   vector<int>ans;
   void solve(TreeNode* root){
     if(root == NULL) return;
     ans.push_back(root->val);
     solve(root->left);
     solve(root->right);

   }
    int minDiffInBST(TreeNode* root) {
        ans.clear();
        solve(root);
        sort(ans.begin(),ans.end());
        int a=INT_MAX;
        for(int i=1;i<ans.size();i++){
            a=min(a,ans[i]-ans[i-1]);
        }
        return a;
    }
};