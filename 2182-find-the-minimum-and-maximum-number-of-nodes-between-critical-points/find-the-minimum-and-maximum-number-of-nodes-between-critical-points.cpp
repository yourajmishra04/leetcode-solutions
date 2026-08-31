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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next == NULL) return {-1,-1};
        ListNode* a = head;
        ListNode* b=head->next;
        ListNode* c = b->next;
        int idx=1;
        int f=-1, s=-1;
        int idxf=-1, idxs=-1, mind=INT_MAX;
        while(c!=NULL){
            if(b->val > a->val && b->val > c->val || b->val < a->val && b->val < c->val){

                if(idxf==-1) idxf=idx;
                else idxs=idx;
                  
                  f=s;
                  s=idx;
                  if(f!=-1){
                  mind= min(mind, s-f );
                  }
                


            }
              a=a->next;
                  b=b->next;
                  c=c->next;
                  idx++;
        }
        if(idxs==-1) return {-1,-1};
        return {mind , idxs-idxf};

    }
};