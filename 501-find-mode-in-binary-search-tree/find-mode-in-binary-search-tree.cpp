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
public:map<int,int>mp;
  void solve(TreeNode* root){
    if(root==NULL) return;
    mp[root->val]++;
    solve(root->left);
    solve(root->right);
  }
    vector<int> findMode(TreeNode* root) {
        mp.clear();
        solve(root);
        vector<vector<int>> v;
        for(auto it : mp) v.push_back({it.second , it.first});
        sort(v.rbegin(),v.rend());
        vector<int>ans;
        int k=v[0][0];
        int i=0 , n=v.size();
          while(i<n && k<=v[i][0]){
            ans.push_back(v[i][1]);
            i++;
          }
          return ans;
    }
};