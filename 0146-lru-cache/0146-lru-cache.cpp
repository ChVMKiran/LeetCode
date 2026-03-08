class Node {
public:
    int key, val;
    Node *prev;
    Node *next;
    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* start;
    Node* end;
    LRUCache(int capacity) {
        cap = capacity;
        start = new Node(-1, -1);
        end = new Node(-1, -1);
        start->next = end;
        end->prev = start;
    }
    
    int get(int key) {
        if(cache.count(key)) {
            int val = cache[key]->val;
            remove(cache[key]);
            insert(cache[key]);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            remove(cache[key]);
        }
        Node* nn = new Node(key, value);
        cache[key] = nn;
        insert(cache[key]);
        if(cache.size() > cap) {
            Node* lru = start->next;
            remove(cache[lru->key]);
            cache.erase(lru->key);
            delete lru;
        }
    }
    ~LRUCache() {
        Node* temp = start;
        while(temp) {
            Node* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
    }
private:
    void insert(Node* node) {
        Node* prev = end->prev;
        prev->next = node;
        node->prev = prev;
        node->next = end;
        end->prev = node;
    }
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
};
