
class Node {
public:
    unordered_map<char, Node*> children;
    unordered_map<int, char> mapping;
    int child_num; 
    bool endOfWord = false;
};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node;
    }
    
    bool insert(string word) {
        Node* curr = root;
        bool broken = true;
        for (char c : word) {
            if (!curr->children.contains(c)) {
                broken = false; 
                Node* new_node = new Node;
                curr->children[c] = new_node;
                curr->children[c]->child_num = curr->children.size();
                curr->mapping[curr->children.size()] = c;
            }
            if (curr->mapping[curr->children.size()] != c) return false;
            curr = curr->children[c];
        }
        if (broken && !curr->children.empty()) return false;
        curr->endOfWord = true;
        return true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->children.contains(c)) return false;
            curr = curr->children[c];
            cout << curr->child_num << endl;
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

    void filler(unordered_map<char, vector<char>>& adj_list) {
        // Node* curr = root;
        stack<Node*> s; s.push(root);
        while (!s.empty()) {
            Node* n = s.top(); s.pop();
            helper(n, adj_list);
            for (const auto& a : n->children) {
                s.push(a.second);
            }
        }
        
    }

    void helper(Node* curr, unordered_map<char, vector<char>>& adj_list) {
        if (curr->children.size() > 1) {
            for (int i = 1; i < curr->mapping.size(); i++) {
                adj_list[curr->mapping[i]].push_back(curr->mapping[i+1]);
            }
        }
    }
};


class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        string ans;
        unordered_map<char, bool> last_ditch;
        for (const auto& w : words) {
            for (const auto& wi : w) {
                last_ditch[wi] = false;
            }
        }
        PrefixTree trie;
        if (words.empty()) return "";
        for (const string& s : words) {
            if (!trie.insert(s)) { cout << "insert failed on: " << s << endl; return ""; }
        }
        
        char first_letter = words[0][0];
        unordered_map<char, vector<char>> adj_list;
        trie.filler(adj_list);


        unordered_set<char> visited;
        unordered_set<char> path;
        if (!dfs(first_letter, adj_list, visited, path, ans, last_ditch)) return "";
        for (const auto& a : last_ditch) {
            if (!a.second) {
                if (!dfs(a.first, adj_list, visited, path, ans, last_ditch)) return "";
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
    bool dfs(char c, unordered_map<char, vector<char>>& adj_list, unordered_set<char>& visited, unordered_set<char>& path, string& ans, unordered_map<char, bool>& last_ditch) {
        if (path.contains(c)) { cout << "cycle at: " << c << endl; return false; }
        if (visited.contains(c)) return true;
        path.insert(c);
        visited.insert(c);
        for (char neighbor : adj_list[c]) {
            if (!dfs(neighbor, adj_list, visited, path, ans, last_ditch)) return false;
        }
        path.erase(c);
        ans += c;
        last_ditch[c] = true;
        return true;

    }
};
