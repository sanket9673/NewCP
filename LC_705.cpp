class MyHashSet {
    private : 
        vector<bool> mp ;
    public:
        MyHashSet() {
            mp.resize(1000001, false) ; // 10^6
        }
        
        void add(int key) {
            mp[key] = true ;
        }
        
        void remove(int key) {
            mp[key] = false ;
        }
        
        bool contains(int key) {
            return mp[key] ;
        }
    };
    
    /**
     * Your MyHashSet object will be instantiated and called as such:
     * MyHashSet* obj = new MyHashSet();
     * obj->add(key);
     * obj->remove(key);
     * bool param_3 = obj->contains(key);
     */