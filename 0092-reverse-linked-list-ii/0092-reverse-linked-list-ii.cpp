class Solution {
public:
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode *curr = start, *prev = end, *nxt = start -> next;
        while(nxt != end) {
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        if(prev != end) return prev;
        return start;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *start = head, *end = head, *prev = NULL;
        while(1) {
            if(--left > 0) prev = start, start = start -> next;
            if(right-- > 0) end = end -> next;
            if(right <= 0 && left <= 0) break;
        }
        if(prev) prev -> next = reverse(start, end);
        else head = reverse(start, end);
        return head;
    }
};