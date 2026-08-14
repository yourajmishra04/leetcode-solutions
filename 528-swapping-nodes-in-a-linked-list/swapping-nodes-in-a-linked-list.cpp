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
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int s=0;
        while(temp!=NULL) {
            s++;
            temp=temp->next;
        }  
         
         int n1=s-k;
           ListNode* t1=head;
             ListNode* t2=head;

             for(int i=0;i<k-1;i++) t1=t1->next;

             for(int i=0;i<n1;i++) t2=t2->next;
              
              int tt= t1->val;
              t1->val=t2->val;
              t2->val=tt;

              return head;


    }
};