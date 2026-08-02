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
    bool ans, flg;
    void solve(queue<TreeNode*>& q) {
        if (q.empty())
            return;
        vector<int> v;
        queue<TreeNode*> qq;
        while (q.size() > 0) {
            TreeNode* root = q.front();
            q.pop();
            v.push_back(root->val);
            if (root->left != NULL)
                qq.push(root->left);
            if (root->right != NULL)
                qq.push(root->right);
        }

        if (flg == 1) {
            if (v[0] % 2 == 1) {
                ans = 0;
                return;
            }
            for (int i = 1; i < v.size(); i++) {
                if (v[i] >= v[i - 1] || v[i] % 2 == 1) {
                    ans = 0;
                    return;
                }
            }
            flg=0;
        }
        else {
            if (v[0] % 2 == 0) {
                ans = 0;
                return;
            }
            for (int i = 1; i < v.size(); i++) {
                if (v[i] <= v[i - 1] || v[i] % 2 == 0) {
                    ans = 0;
                    return;
                }
            }
            flg=1;
        }
        solve(qq);
    }
    bool isEvenOddTree(TreeNode* root) {
        ans=1;
        flg=0;
        queue<TreeNode*> q;
        q.push(root);
        solve(q);
        return ans;



    }
};