class LRUCache {
public:
    //DLL
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        //constructor
        Node(int _key, int _val){
            key = _key;
            val= _val;
        }
    };

    // head and tail dummy nodes
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    // cache capacity
    int cap;
    //hash map to store key-node mapping
    unordered_map<int, Node*>m;
    
    // insert node right after head
    void addNode(Node* newNode){
        Node* temp = head->next;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
        head->next = newNode;
    }

    // remove given node from list
    void deleteNode(Node* delNode){
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev; 
    }

    LRUCache(int capacity) {
        cap= capacity;
        head->next = tail;
        tail->prev= head;
    }
    
    int get(int key_) {
        // if key exits in cache
        if(m.find(key_)!=m.end()){
            Node* resNode = m[key_];
            int res= resNode->val;

            //remove old mapping
            m.erase(key_);

            //move accessed node to front
            deleteNode(resNode);
            addNode(resNode);

            // update map
            m[key_]= head->next;
            return res;
        }
        // if not found
        return -1;
    }
    
    void put(int key_, int value) {
        // if key already exits
        if(m.find(key_)!=m.end()){
            Node* existingNode= m[key_];
            m.erase(key_);
            deleteNode(existingNode);
        }

        // if capacity reached
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        // Insert new node at front
        addNode(new Node(key_, value));
        m[key_]= head->next;
    }
};
