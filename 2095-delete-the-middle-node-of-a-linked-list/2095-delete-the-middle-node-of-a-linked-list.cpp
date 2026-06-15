class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            if(fast && fast->next) slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};