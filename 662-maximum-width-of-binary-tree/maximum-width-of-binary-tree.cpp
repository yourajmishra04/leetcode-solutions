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
    long long ans = 0;
    void solve(queue<pair<TreeNode*, long long>>& q) {

        while (!q.empty()) {

            int n = q.size();
            long long first = q.front().second;
            long long last = first;
            for (int i = 0; i < n; i++) {

                auto [node, idx] = q.front();
                q.pop();

                idx -= first;

                last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx});

                if (node->right)
                    q.push({node->right, 2 * idx + 1});
            }

            ans = max(ans, last + 1);
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> vv;
        vv.push({root, 0});
        solve(vv);
        return ans;
    }
};