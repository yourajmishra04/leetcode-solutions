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

     void solve(TreeNode* root, int i ,int j , vector<vector<string>>& ans , int level){
        if(root == NULL) return ;
        int mid=(i+j)/2;
        string s=to_string(root->val)  ;
        ans[level][mid]=s;
        solve(root->left , i , mid-1 , ans ,level+1);
          solve(root->right , mid+1 , j , ans ,level+1);

     }

    vector<vector<string>> printTree(TreeNode* root) {
         
          queue<pair<TreeNode* , int>>q;
          q.push({root , 1});
          int n;
          while(!q.empty()){
               auto [a , b] = q.front();
               q.pop();
               if(a->left!=NULL) q.push({a->left , b+1});
                  if(a->right!=NULL) q.push({a->right , b+1});
               if(q.empty()) n=b;
          }
          long long d=1LL << n;
          d-=1;
          vector<vector<string>>ans(n , vector<string>(d,""));
          solve(root , 0 , d-1 , ans , 0);
          return ans;
            
    }
}; 