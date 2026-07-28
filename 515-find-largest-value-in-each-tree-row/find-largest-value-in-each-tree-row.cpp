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
     vector<int> ans;
     void solve(queue<TreeNode*>& q){
        if(q.empty()) return;
        queue<TreeNode*> qq;
        int mx=INT_MIN;
        while(!q.empty()){
            TreeNode* root=q.front();
            q.pop();
            mx=max(mx,root->val);
            if(root->left !=NULL) qq.push(root->left);
            if(root->right!=NULL) qq.push(root->right);
            
        }
        ans.push_back(mx);
        solve(qq);
     }
    vector<int> largestValues(TreeNode* root) {
        ans.clear();
        if(root==NULL) return ans;
        queue<TreeNode*> qq;
        qq.push(root);
        solve(qq);
        return ans;
    }
};