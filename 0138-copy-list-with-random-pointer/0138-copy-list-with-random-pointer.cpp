class Solution {
public:
    void copyNext(Node* head) {
        Node* temp = head;
        while(temp) {
            Node* nn = new Node(temp->val);
            nn->next = temp->next;
            temp->next = nn;
            temp = nn->next;
        }
    }
    void copyRand(Node* head) {
        Node* temp = head;
        while(temp) {
            Node* nn = temp->next;
            if(temp->random) nn->random = temp->random->next;
            temp = nn->next;
        }
    }
    Node* concNew(Node* head) {
        Node *temp1 = head, *temp2 = head->next, *res = head->next;
        while(temp2 && temp2->next) {
            temp1 = temp1->next = temp1->next->next;
            temp2 = temp2->next = temp2->next->next;
        }
        temp1->next = nullptr;
        return res;
    }
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        copyNext(head);
        copyRand(head);
        return concNew(head);
    }
};