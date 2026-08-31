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
       bool flg=0;
       void solve(queue<TreeNode* >&q , map<int,int>& mp, int x, int y){

            if(mp.empty()) return;
        
         
          for(auto it : mp){
              if(it.first == x && mp.find(y)!=mp.end() && mp[x]!=mp[y]) {
                flg=1;
                return;
              }
               if(it.first == y && mp.find(x)!=mp.end() && mp[x]!=mp[y]) {
                flg=1;
                return;
              }
          }

          mp.clear();
          queue<TreeNode*>qq;
          while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left!=NULL){
                qq.push(curr->left);
                mp[curr->left->val]=  curr->val;
            }
            if(curr->right!=NULL){
                qq.push(curr->right);
                mp[curr->right->val]=  curr->val;
            }
          }

             solve(qq,mp,x,y);

       }
    bool isCousins(TreeNode* root, int x, int y) {

        queue<TreeNode*>qq;
        qq.push(root);
        map<int,int>mp;
        mp[root->val]=-1;
        solve(qq,mp,x,y);
        return flg;
    }
};