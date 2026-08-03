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
class BSTIterator {
public:
  TreeNode* root;
  vector<int>ans;
  int idx=0;
    void solve(TreeNode* root){
        if(root==NULL) return;
        solve(root->left);
        ans.push_back(root->val);
        solve(root->right);

    }
    BSTIterator(TreeNode* Root) {
        root=Root;
        ans.clear();
        solve(root);
    }
    
    int next() {
        int n=ans[idx];
        idx++;
        return n;
    }
    
    bool hasNext() {
         if(idx<ans.size()) return 1;
         return 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */