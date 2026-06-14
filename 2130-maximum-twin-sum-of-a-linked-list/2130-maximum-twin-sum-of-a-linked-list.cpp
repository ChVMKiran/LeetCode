class Solution {
public:
    ListNode* solve(ListNode* p, ListNode*& q, int& ans) {
        if(!p) return q;
        q = solve(p->next, q, ans);
        ans = max(ans, p->val + q->val);
        return q->next;
    }
    int pairSum(ListNode* head) {
        int ans = 0;
        solve(head, head, ans);
        return ans;
    }
};