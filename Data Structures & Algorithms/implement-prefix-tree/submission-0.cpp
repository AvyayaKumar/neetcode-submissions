class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord = false;
};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node;
    }
    
    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->children.contains(c)) {
                Node* new_node = new Node;
                curr->children[c] = new_node;
            }
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->children.contains(c)) return false;
            curr = curr->children[c];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for (char c : prefix) {
            if (!curr->children.contains(c)) return false;
            curr = curr->children[c];
        }
        return true;
    }
};
