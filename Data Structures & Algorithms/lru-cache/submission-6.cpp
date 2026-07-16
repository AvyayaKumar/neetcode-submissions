class Node {
public:
    Node* prev = nullptr;
    Node* next = nullptr;
    int val;
    int key;
    Node(int skey, int sval) {
        val = sval;
        key = skey;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left_pointer; Node* right_pointer;

    LRUCache(int capacity) {
        cap = capacity;
        Node* dummy_node = new Node(-1, -1);
        left_pointer = dummy_node; right_pointer = dummy_node;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            int ans = cache[key]->val;
            //update linked list
            Node* prv = cache[key]->prev;
            Node* nxt = cache[key]->next;
            if (nxt) {
                prv->next = nxt; nxt->prev = prv;
                Node* new_node = new Node(key, ans); cache[key] = new_node; right_pointer->next = new_node; new_node->prev = right_pointer;
                right_pointer=right_pointer->next;
            }

            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key]->val = value;
            Node* prv = cache[key]->prev; Node* nxt = cache[key]->next;
            if (nxt) {
                prv->next = nxt; nxt->prev = prv;
                Node* new_node = new Node(key, value); cache[key] = new_node; right_pointer->next = new_node; new_node->prev = right_pointer;
                right_pointer=right_pointer->next;
            }
        } else {
            Node* new_node = new Node(key, value); cache[key] = new_node;
            right_pointer->next = new_node; new_node->prev = right_pointer; right_pointer=right_pointer->next;
        }

        if (cache.size() > cap) {
            Node* rmve = left_pointer->next;
            rmve->next->prev = rmve->prev;
            rmve->prev->next = rmve->next;
            cache.erase(rmve->key);
        }
    }
};
