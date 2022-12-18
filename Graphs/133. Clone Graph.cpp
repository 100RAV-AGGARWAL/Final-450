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
    map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        if(mp.find(node) == mp.end()) {
            Node* src = new Node(node->val, {});
            mp[node] = src;

            for(auto it : node->neighbors) {
                Node *neigh = cloneGraph(it);

                if(neigh)
                    (src->neighbors).push_back(neigh);
            }
        }

        return mp[node];
    }
};