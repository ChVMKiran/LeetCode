class Solution {
public:
    void solve(ListNode* p, ListNode*& q, int& ans) {
        if(!p) return;
        solve(p->next, q, ans);
        ans = max(ans, p->val + q->val);
        q = q->next;
    }
    int pairSum(ListNode* head) {
        int ans = 0;
        solve(head, head, ans);
        return ans;
    }
};