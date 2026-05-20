/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    void lcaP(unordered_set<Node*>&pSet, Node* p){
        while(p!=NULL){
            pSet.insert(p);
            p=p->parent;
        }
    }
    Node* checkQ(unordered_set<Node*>&pSet, Node* q){
        while(q!=NULL){
            if(pSet.find(q)!=pSet.end()) return q;
            q=q->parent;
        }
        return NULL;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*>pSet;
        lcaP(pSet, p);
        return checkQ(pSet,q);   
        
    }
};