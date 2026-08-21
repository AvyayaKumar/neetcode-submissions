class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord = false;
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node;
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->children.contains(c)) curr->children[c] = new Node;
            curr = curr->children[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, root, 0);
    }

    bool dfs(string word, Node* curr, int i) {
        if (!curr) return false;
        if (i == word.length()-1) {
            if (curr->children.contains(word[i])) return curr->children[word[i]]->endOfWord;
            if (word[i] == '.') {
                for (auto it : curr->children) {
                    if (it.second->endOfWord) return true;
                }
            }
            return false;
        }
        if (word[i] != '.' && !curr->children.contains(word[i])) return false;
        if (word[i] != '.') {
            if (dfs(word, curr->children[word[i]], i+1)) return true;
        } else {
            // vector<Node*> nodes;
            for (auto it : curr->children) {
                if (dfs(word, it.second, i+1)) return true;
            }
        }
        return false;
    }
};
