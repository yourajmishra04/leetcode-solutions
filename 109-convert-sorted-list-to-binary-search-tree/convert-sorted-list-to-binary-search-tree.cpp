/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
       
        TreeNode* solve(int i, int j){

            if(i>j) return NULL;
            int mid=(i+j)/2;
              TreeNode* root= new TreeNode(v[mid]);

          TreeNode* l = solve(i, mid-1);

           TreeNode* r = solve(mid+1, j);

           root->left=l;
           root->right=r;


                 return root;

        }
     
    TreeNode* sortedListToBST(ListNode* head) {
        v.clear();
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
          int n=v.size()-1;
               TreeNode* root=solve(0,n);

               return root;
    }
};