class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head, *prev = NULL;
        while(curr && curr->next) {
            if(curr->val == curr->next->val) {
                int x = curr->val;
                while(curr && curr->val == x) {
                    curr = curr->next;
                }
                if(prev) prev->next = curr;
                else head = curr;
                continue;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};