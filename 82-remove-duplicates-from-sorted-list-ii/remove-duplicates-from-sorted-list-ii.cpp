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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode* i = head;
        ListNode* j=head;
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        j=j->next;
        while(j!=NULL){
            j=i->next;
             while(j!=NULL && j->val==i->val ) j=j->next;

             if(i->next == j) {
                temp->next=i;

                temp=temp->next;
                temp->next=NULL;
                i=j;
             } 
             else{
                i=j;
             }

        }
        if(temp==ans) temp->next=i;
        
        return ans->next;
    }
};