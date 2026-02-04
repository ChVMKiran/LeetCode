/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode*temp=head,*pre=NULL,*start=NULL,*curr=head,*prev=NULL,*nxt=NULL;
        while(temp){
            n++;
            temp=temp->next;
        }
        for(int i=0;i<n/k;i++){
            temp=curr;
            int j=k;
            while(j--){
                temp=temp->next;
            }
            prev=temp;
            // cout<<temp->val;
            bool flag=true;
            while(curr!=temp){
                if(flag){
                    start=curr;
                    flag=false;
                }
                nxt=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nxt;
            }
            if(pre)pre->next=prev;
            else head=prev;
            pre=start;
            if(curr)cout<<curr->val;
        }
        return head;
    }
};