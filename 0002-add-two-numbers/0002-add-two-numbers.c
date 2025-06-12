/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode*res=NULL,*prv=NULL;
    int i,rem=0,ans;
    while(l1||l2){
        if(l1&&l2){
            ans=l1->val+l2->val+rem;
            l1=l1->next;
            l2=l2->next;
        }
        else if(l1){
            ans=l1->val+rem;
            l1=l1->next;
        }
        else if(l2){
            ans=l2->val+rem;
            l2=l2->next;
        }
        rem=ans/10;
        struct ListNode*nn=(struct ListNode*)malloc(sizeof(struct ListNode));
        nn->val=ans%10;
        nn->next=NULL;
        if(!res){
            res=nn;
            prv=nn;
        }
        else{
            prv->next=nn;
            prv=prv->next;
        }
    }
    if(rem){
        struct ListNode*nn=(struct ListNode*)malloc(sizeof(struct ListNode));
        nn->val=rem;
        nn->next=NULL;
        prv->next=nn;
    }
    return res;
}