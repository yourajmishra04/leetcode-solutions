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
      vector<int>v;
      void solve(queue<TreeNode*>& q){
        if(q.empty()) return ;

        int tot=0;
        queue<TreeNode*>qq;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            tot+=it->val;
            if(it->left!=NULL) 
                qq.push(it->left);
                if(it->right!=NULL) 
                qq.push(it->right);
            
        }
        v.push_back(tot);
        solve(qq);


      }
    int maxLevelSum(TreeNode* root) {
        v.clear();
         queue<TreeNode*>qq;
         qq.push(root);
         solve(qq);
         int ans=1 , mx=v[0];
         for(int i=1;i<v.size();i++){
            if(mx<v[i]) {
                mx=v[i];
                ans=i+1;
            }
         }
         return ans;
    }
};