class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int size = 0;
        ListNode* temp = head, *end = head;
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
            end->next = head;
            head = temp->next;
            temp->next = nullptr;
        }
        return head;
    }
};