class Solution {
public:
    ListNode* reverse(ListNode* num) {
        ListNode *curr = num, *nxt = NULL, *prv = NULL;
        while (curr) {
            nxt = curr->next;
            curr->next = prv;
            prv = curr;
            curr = nxt;
        }
        return prv;
    }
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        num1 = reverse(num1);
        num2 = reverse(num2);
        ListNode *ans = NULL, *temp = NULL;
        int carry = 0;
        while (num1 || num2) {
            int first = 0, second = 0;
            if (num1) {
                first = num1->val;
                num1 = num1->next;
            }
            if (num2) {
                second = num2->val;
                num2 = num2->next;
            }
            if (ans) {
                temp->next = new ListNode((first + second + carry) % 10);
                temp = temp->next;
            } else {
                ans = new ListNode((first + second + carry) % 10);
                temp = ans;
            }
            carry = (first + second + carry) / 10;
        }
        if (carry) {
            temp->next = new ListNode(carry);
            temp = temp->next;
        }
        ans = reverse(ans);
        while (ans->next && ans->val == 0)
            ans = ans->next;
        return ans;
    }
};