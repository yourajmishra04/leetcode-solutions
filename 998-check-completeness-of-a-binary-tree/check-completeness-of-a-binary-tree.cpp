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
  bool flg,ans;

    void solve(queue<TreeNode*>& q){
        if(q.empty()) return;
        
        queue<TreeNode*> qq;

        while(q.size()>0){

            TreeNode* node=q.front();
            q.pop();
            if(node->left== NULL) flg=1;
            else {
                if(flg==1) {
                    ans=0;
                    return;
                }
                qq.push(node->left);

            }
            if(node->right== NULL) flg=1;
            else {
                if(flg==1) {
                    ans=0;
                    return;
                }
                qq.push(node->right);
                
            }
        }

        solve(qq);


    }
   

    bool isCompleteTree(TreeNode* root) {
       
        ans=1;
         queue<TreeNode*> qq;
      qq.push(root);
      solve(qq);
      return ans;
   
    }
};