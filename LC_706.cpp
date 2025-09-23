class MyHashMap {
    private:
        vector<pair<int,int>> mp; // store (key, value)
        
    public:
        MyHashMap() {
        }
        
        void put(int key, int value) {
            for (auto &p : mp) {
                if (p.first == key) {
                    p.second = value;
                    return;
                }
            }
            mp.push_back({key, value});
        }
        
        int get(int key) {
            for (auto &p : mp) {
                if (p.first == key) return p.second;
            }
            return -1;
        }
        
        void remove(int key) {
            for (int i = 0; i < (int)mp.size(); ++i) {
                if (mp[i].first == key) {
                    mp.erase(mp.begin() + i); // remove the pair
                    return;
                }
            }
        }
    };
    // class MyHashMap {
    // public:
    //     vector<vector<int>> mp ; // doesnt guarentee the inner size is 2 [key,val] == use PAIR
    //     MyHashMap() {
    //     }
        
    //     void put(int key, int value) {
    //         bool fnd = false ;
    //         for (int i = 0; i < mp.size(); i++) {
    //             if (mp[i][0] == key){
    //                 mp[i][1] = value ;
    //                 fnd = true ;
    //             }
    //         }
    //         if (fnd == false) mp.push_back({key, value}) ;
    //     }
        
    //     int get(int key) {
    //         int res = -1 ;
    //         for (int i = 0; i < mp.size(); i++) {
    //             if (mp[i][0] == key) {
    //                 res = mp[i][1] ;
    //                 break ;
    //             }
    //         }
    //         return res ;
    //     }
        
    //     void remove(int key) {
    //         for (int i = 0; i < mp.size(); i++) {
    //             if (mp[i][0] == key) {
    //                 // NULL is a pointer constant; assigning it to int is wrong. Use a sentinel (-1) or better, erase the element.
    //                 mp[i][0] = -1 ;
    //                 mp[i][1] = -1 ;
    //                 break ;
    //             }
    //         }
    //     }
    // };
    
    // /**
    //  * Your MyHashMap object will be instantiated and called as such:
    //  * MyHashMap* obj = new MyHashMap();
    //  * obj->put(key,value);
    //  * int param_2 = obj->get(key);
    //  * obj->remove(key);
    //  */