
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> n1;
        stack<int> n2;
        stack<int> n3;
        ListNode* temp1 = l1;
        int num1 = 0;
        while (temp1 != NULL) {
            n3.push(temp1->val);
            temp1 = temp1->next;
        }
           while(n3.size()>0){
            n1.push(n3.top());
            n3.pop();
           }
        temp1 = l2;
        int num2 = 0;
        while (temp1 != NULL) {
            n3.push(temp1->val);
            temp1 = temp1->next;
        }
         while(n3.size()>0){
            n2.push(n3.top());
            n3.pop();
           }

        int carry = 0;
        ListNode* result = new ListNode(10);
        ListNode* ans = result;
        while (n1.size() > 0 || n2.size() > 0 || carry > 0) {
            int sum = carry;
            if (n1.size() > 0) {
                sum += n1.top();
                n1.pop();
            }
            if (n2.size() > 0) {
                sum += n2.top();
                n2.pop();
            }
            ListNode* newNode = new ListNode(sum % 10);
            result->next = newNode;
            result = newNode;
            carry = sum / 10;
        }
        return ans->next;
    }
};