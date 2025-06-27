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
        ListNode* dummy = new ListNode(0, head);
        ListNode *start = head, *end = head, *prev = dummy;
        while(1) {
            if(--left > 0) prev = start, start = start -> next;
            if(right-- > 0) end = end -> next;
            if(right <= 0 && left <= 0) break;
        }
        prev -> next = reverse(start, end);
        return dummy -> next;
    }
};