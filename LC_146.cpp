// queue data structure gets limited when we want access of elements in o(1)
class LRUCache {
public:
    class Node {
        public: // allocate the accesser else error
            int key ;
            int val ;
            Node* next ;
            Node* prev ;
            Node (int key, int val) {   // shadowing (using same name, use this-> else error will come)
                this->key = key ;
                this->val = val ;
                // 2. .this -> missed
                next = nullptr ;
                prev = nullptr ;
            }
    } ;

    int cap = 0 ;
    unordered_map<int, Node*> res ;
    Node* head = new Node(-1, -1) ; // dummy node
    Node* tail = new Node(-1, -1) ; // dummy node

    void addnode(Node* newnode) {
    // new node (used node) should be added/updated to front
    // head pointing at -1 (default)
        Node* temp = head -> next ;
        newnode -> next = temp ;
        newnode -> prev = head ;
        head -> next = newnode ; 
        temp -> prev = newnode ; // updated the tail part prev 
    }
    void deletenode(Node* newnode) {
    // node to be deleted must be removed from the tail
    // tail pointing at -1 (default)
        Node* prevdel = newnode -> prev ;
        Node* nextdel = newnode -> next ;
        prevdel -> next = nextdel ;
        nextdel -> prev = prevdel ;
    }

    LRUCache(int capacity) { // constructor
        cap = capacity ;
        head -> next = tail ;
        tail -> prev = head ;
    }
    
    int get(int key) {
        if (res.count(key) == 0) return -1 ;
        else {
            int answer = res[key] -> val ;
            deletenode(res[key]) ; // delete old
            addnode(res[key]) ;  // add again
            res.erase(key) ;
            res[key] = head -> next ; // as head = -1, next to it is updated node
            return answer ;
        }
    }
    
    void put(int key, int value) {
        if (res.count(key) != 0) { // key exist
            deletenode(res[key]) ;
            addnode(res[key]) ;
            // update the value     -> 1.missed
            head -> next -> val = value ;
        }
        else {
            if (res.size() == cap) {
                int toerasekey = tail -> prev -> key ;
                res.erase(toerasekey) ;
                deletenode(tail -> prev) ;
                
            }
            // add the new key 
            addnode(new Node(key, value)) ;
            res[key] = head -> next ;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */