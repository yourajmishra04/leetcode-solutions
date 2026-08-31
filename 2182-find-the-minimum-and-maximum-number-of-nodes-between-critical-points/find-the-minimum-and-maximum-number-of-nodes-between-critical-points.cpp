
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 1;
        int idxf = -1;
        int idxs = -1;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = b->next;
        int mind = INT_MAX;

        int f = -1;
        int s = -1;
        if (c == NULL)
            return {-1, -1};
        while (c) {
            if (b->val > a->val && b->val > c->val ||
                b->val < a->val && b->val < c->val) {
                if (idxf == -1)
                    idxf = idx;
                else
                    idxs = idx;
            
            f = s;
            s = idx;
            if (f != -1) {
                int d = s - f;
                mind = min(mind, d);
            }}
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if (idxs == -1)
            return {-1, -1};
        int maxd = idxs - idxf;

        return {mind, maxd};
    }
};