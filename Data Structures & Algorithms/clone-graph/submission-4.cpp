/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> nodes;
    unordered_map<int, vector<int>> mp;
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        Node* new_node;
        if (nodes.find(node->val) == nodes.end()) {
            new_node = new Node(node->val);
            nodes[node->val] = new_node;
            mp[node->val] = {};
        } else {
            new_node = nodes[node->val];
        }
        
        for (int i = 0; i < node->neighbors.size(); i++) {
        
            if (nodes.find(node->neighbors[i]->val) == nodes.end()) {
                if (node->neighbors[i]->val == 4) cout << "hi, im bob" << endl;
                Node* new_neighbor = new Node(node->neighbors[i]->val);
                nodes[node->neighbors[i]->val] = new_neighbor;
                new_node->neighbors.push_back(new_neighbor);
                new_neighbor->neighbors.push_back(new_node);
                mp[node->val].push_back(new_neighbor->val);
                mp[new_neighbor->val] = {node->val};
                cloneGraph(node->neighbors[i]);
            } else if (find(mp[node->val].begin(), mp[node->val].end(), node->neighbors[i]->val) == mp[node->val].end()) {
                Node* new_neighbor = nodes[node->neighbors[i]->val];
                new_node->neighbors.push_back(new_neighbor);
                new_neighbor->neighbors.push_back(new_node);
                mp[node->val].push_back(new_neighbor->val);
                mp[new_neighbor->val].push_back(node->val);
            }
            
        }

        // for (int i = 0; i < node->neighbors.size(); i++) {

        // }
        
        return new_node;
    }
};
