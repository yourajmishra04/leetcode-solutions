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
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int lft = solve(root->left);
        int rght = solve(root->right);
        int mx = max(lft, rght);

        if(root->val >= mx) ans++;
        return max(mx,root->val); 
    }
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return ans;
    }
};