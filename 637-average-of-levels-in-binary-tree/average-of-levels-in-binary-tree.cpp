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
 vector<double>ans;
    void solve(queue<TreeNode*>& q){
        queue<TreeNode*> qq;
        long double tot=0,n=q.size();
        if(n==0) return;
        while(!q.empty()){
TreeNode* root= q.front();
tot+=root->val;
if(root->left!=NULL) qq.push(root->left);
if(root->right!=NULL) qq.push(root->right);
  q.pop();
        }
        tot/=n;
        ans.push_back(tot);
        solve(qq);
        
    }
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        ans.clear();
        q.push(root);
        solve(q);
        return ans;
    }
};