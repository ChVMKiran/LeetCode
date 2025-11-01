class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> ust(nums.begin(), nums.end());
        ListNode *ans = nullptr, *newHead = ans, *temp = head;
        for(ListNode* temp = head; temp; temp = temp -> next) {
            if(ust.count(temp -> val)) continue;
            if(!ans) newHead = ans = temp;
            else ans = ans -> next = temp;
        }
        if(ans) ans -> next = nullptr;
        return newHead;
    }
};