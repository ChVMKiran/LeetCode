class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int size = 0;
        ListNode* temp = head, *newHead = head, *end = head;
        while(temp) {
            end = temp;
            temp = temp->next;
            size++;
        }
        k %= size;
        if(!k) return head;
        temp = head;
        k = size - k;
        while(--k) {
            temp = temp->next;
        }
        if(temp) {
            newHead = temp->next;
            temp->next = nullptr;
            end->next = head;
        }
        return newHead;
    }
};