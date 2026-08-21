class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord = false;
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node;
    }
    void insert(string word) {
        Node* curr = root;
        for (char c : word) {
            if (!curr->children.contains(c)) curr->children[c] = new Node;
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
};

class Solution {
public:
    Trie t;
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), 0));
        for (int i = 0; i < words.size(); i++) t.insert(words[i]);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                string blank = "";
                vector<vector<bool>> x = visited;
                floodfill(board, t.root, i, j, blank, x);
            }
        }
        return ans;
    }
    void floodfill(vector<vector<char>>& board, Node* curr, int r, int c, string currWord, vector<vector<bool>>& visited) {
        // if (!curr) return;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (visited[r][c]) return;
        // if (curr->endOfWord) ans.push_back(currWord);
        if (curr->children.contains(board[r][c])) {
            currWord += board[r][c];
            visited[r][c] = 1;
            curr = curr->children[board[r][c]];
            if (curr->endOfWord) {
                ans.push_back(currWord);
                curr->endOfWord = false;
            }
            floodfill(board, curr, r+1, c, currWord, visited);
            floodfill(board, curr, r, c-1, currWord, visited);
            floodfill(board, curr, r, c+1, currWord, visited);
            floodfill(board, curr, r-1, c, currWord, visited);
            visited[r][c] = 0;
        }
    }
};
