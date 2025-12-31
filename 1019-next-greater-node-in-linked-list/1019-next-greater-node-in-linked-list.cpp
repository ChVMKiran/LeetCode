class Solution {
public:
    ListNode* rev(ListNode* head) {
        ListNode* curr = head;
        ListNode* nxt = nullptr;
        ListNode* prev = nullptr;
        while(curr) {
            nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> st;
        head = rev(head);
        while(head) {
            while(!st.empty() && st.top() <= head -> val)st.pop();
            if(!st.empty()) {
                ans.push_back(st.top());
            }
            else ans.push_back(0);
            st.push(head -> val);
            head = head -> next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};