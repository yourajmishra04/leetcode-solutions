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
    void solve(TreeNode* &root , TreeNode* root1, TreeNode* root2){
                 if(root1==NULL && root2==NULL) return ;

                  if(root1==NULL || root2==NULL) {
                               if(root1!=NULL) root=root1;
                               else root=root2;
                               return;
                  }

                   TreeNode* temp=new  TreeNode(root1->val + root2->val);
                   root=temp;

                   solve(root->left, root1->left,root2->left);

                  solve(root->right, root1->right,root2->right);




    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        

        TreeNode* root= NULL;

        solve(root,root1,root2);


         return root;

    }
};