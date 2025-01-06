// Problem: https://leetcode.com/problems/lru-cache/description/

class LRUCache {
struct node {
    int key, val;
    struct node* prev, *next;

    node(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

    unordered_map<int, node*>map;
    node *head, *tail;
    int curr, cap;

    void removeNode(node* n) {
        n->prev->next=n->next;
        n->next->prev=n->prev;
    }

    void insertAtFront(node* n) {
        n->next=head->next;
        n->prev=head;
        head->next->prev=n;
        head->next=n;
    }

public:
    LRUCache(int capacity) {
        curr=0;
        cap=capacity;
        head=new node(-1, -1);
        tail=new node(-1, -1);

        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(map.find(key)==map.end())  
            return -1;

        node* n=map[key];
        
        removeNode(n);
        insertAtFront(n);

        return n->val;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()) {
            node* existingNode = map[key];
            existingNode->val = value;
            removeNode(existingNode);
            insertAtFront(existingNode);
        } else {
            if(curr == cap) {
                // Remove LRU node
                node* lru = tail->prev;
                removeNode(lru);
                map.erase(lru->key);
                delete lru;
                curr--;
            }
            // Insert new node
            node* newNode = new node(key, value);
            insertAtFront(newNode);
            map[key] = newNode;
            curr++;
        }
    }
};

