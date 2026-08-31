class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1, mini = -1, i = 0;
        ListNode *temp = head->next, *prev = head;
        while(temp && temp->next) {
            int back = prev->val, curr = temp->val, nxt = temp->next->val;
            if(curr < back && curr < nxt || curr > back && curr > nxt) {
                if(mini > i - last || mini == -1 && last != -1) {
                    mini = i - last;
                }
                if(first == -1) first = i;
                last = i;
            }
            prev = temp;
            temp = temp->next;
            i++;
        }
        return {mini, first == last ? -1 : last - first};
    }
};