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
  vector<int> v;
  void solve(TreeNode* root){
    if(root==NULL) return;
    v.push_back(root->val);
    solve(root->left);
    solve(root->right);
  }
    bool findTarget(TreeNode* root, int k) {
         v.clear();
         solve(root);
         sort(v.begin(),v.end());
         int n=v.size();
         for(int i=0;i<n-1;i++){
             int tar=k-v[i];
             int l=i+1, r=n-1,mid;
             while(l<=r){
                mid=(l+r)/2;
                if(v[mid]==tar) return 1;
                else if(v[mid]>tar) r=mid-1;
                else l=mid+1;
            
             }
         }
         return 0;
    }
};