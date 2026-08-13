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
string ans;
string fans;

   bool end(TreeNode* root, int destValue){

          if(root==NULL) return 0;

          if(root->val == destValue) return 1;

          bool l=end(root->left , destValue);
          bool r=end(root->right , destValue)  ;

          if(l==1) ans+='L';
          if(r==1) ans+='R';
          return l||r;


   }


bool start(TreeNode* root, int startValue){

          if(root==NULL) return 0;

          if(root->val == startValue) return 1;

          bool l=start(root->left , startValue);
          bool r=start(root->right , startValue)  ;

          if(l==1) fans+='L';
          if(r==1) fans+='R';
          return l||r;


   }
    

    string getDirections(TreeNode* root, int startValue, int destValue) {
        ans="";
        end(root,destValue);
        reverse(ans.begin(),ans.end());
         fans="";
        start(root,startValue);
        reverse(fans.begin(),fans.end());

        int i=0, j=0;
        while(i<ans.size()&& j<fans.size() && ans[i]==fans[j]) {
            i++;
            j++;
        }

        int n=fans.size()-j;
        string get(n,'U');
        get+=ans.substr(i);
        return get;
      
    }
};