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
    
    Node* DFS(Node* node,unordered_map<Node*,Node*> &mp){
        if(mp.find(node) != mp.end()){
            return mp[node];
        }
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto neighbour : node->neighbors){
            clone->neighbors.push_back(DFS(neighbour,mp));
        }
        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*,Node*> mp;
        return DFS(node,mp);
    }
};