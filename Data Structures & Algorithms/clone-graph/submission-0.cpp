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
    Node* cloneUtil(Node* node, unordered_map<Node*, Node*>& mpp){
        Node* newNode = new Node(node->val);
        mpp[node]= newNode;

        for(auto neighbor: node->neighbors){
            if(mpp.find(neighbor)==mpp.end()){
                //clone neighbor and also push it in the clone neighbors
                (newNode->neighbors).push_back(cloneUtil(neighbor, mpp));
            }else{
                // push the cloned neighbors in the clone neighbors
                (newNode->neighbors).push_back(mpp[neighbor]);
            }
        }
        return newNode;
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*, Node*>mpp;
        return cloneUtil(node, mpp);
    }
};
