class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root);

        root->val = 0;

        while (!q.empty()) {
            int n = q.size();

            int sum = 0;

            vector<TreeNode*> curr;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                curr.push_back(node);

                if (node->left)
                    sum += node->left->val;

                if (node->right)
                    sum += node->right->val;
            }

            
            for (TreeNode* node : curr) {
                int siblingSum = 0;

                if (node->left)
                    siblingSum += node->left->val;

                if (node->right)
                    siblingSum += node->right->val;

                if (node->left) {
                    node->left->val = sum - siblingSum;
                    q.push(node->left);
                }

                if (node->right) {
                    node->right->val = sum - siblingSum;
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};