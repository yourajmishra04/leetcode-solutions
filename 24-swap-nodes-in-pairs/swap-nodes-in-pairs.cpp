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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp1 = head ; ListNode* temp2=head->next;
        ListNode* ans= new ListNode(0);
        ListNode* temp=ans;

        while(temp1!=NULL && temp2!=NULL){
             ListNode* nxt=temp2->next;
                temp->next=temp2;
                temp=temp->next;
                 temp->next=temp1;
                temp=temp->next;
                temp1=nxt;
                if(temp1==NULL) break;
                temp2=temp1->next;


        }
        temp->next=temp1;
        return ans->next;
    }
};