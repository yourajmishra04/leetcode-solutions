/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    int mod=1e9+7;
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lft = solve(root->left);
        int rght = solve(root->right);
                  v.push_back(lft);
                  v.push_back(rght);

        v.push_back(root->val + lft + rght);
        return root->val + lft + rght;
    }
    int maxProduct(TreeNode* root) {
        v.clear();
        long long tot = solve(root);
        long long ans = 0;
        for (int x : v) {

            long long y = tot - x;
            
            y *= x;
            
            ans = max(ans, y);
        }
        return ans%mod;
    }
};