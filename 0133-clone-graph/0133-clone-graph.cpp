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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        stack<Node*> st;

        mp[node] = new Node(node->val);
        st.push(node);

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();

            for (Node* neigh : curr->neighbors) {
                if (mp.find(neigh) == mp.end()) {
                    mp[neigh] = new Node(neigh->val);
                    st.push(neigh);
                }

                mp[curr]->neighbors.push_back(mp[neigh]);
            }
        }

        return mp[node];
    }
};