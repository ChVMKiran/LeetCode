class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_set<int> ust;
        Node* curr = node;
        queue<Node*> qu;
        qu.push(curr);
        vector<vector<Node*>> adj(101);
        while(!qu.empty()) {
            Node* front = qu.front();
            qu.pop();
            for(auto& n: front->neighbors) {
                int hash = min(n->val * 100 + front->val, front->val * 100 + n->val);
                if(ust.count(hash)) continue;
                ust.insert(hash);
                qu.push(n);
                adj[front->val].push_back(n);
                adj[n->val].push_back(front);
            }
        }
        Node* ans = nullptr;
        unordered_map<int, Node*> ump;
        for(int i = 0; i < 101; i++) {
            Node* curr;
            if(ump.count(i)) {
                curr = ump[i];
            }
            else {
                curr = new Node(i);
                ump[i] = curr;
            }
            for(auto&n: adj[i]) {
                Node* temp;
                if(ump.count(n->val)) {
                    temp = ump[n->val];
                }
                else {
                    temp = new Node(n->val);
                    ump[n->val] = temp;
                }
                (curr->neighbors).push_back(temp);
            }
            if(i == node->val) ans = curr;
        }
        return ans;
    }
};