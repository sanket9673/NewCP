class EventManager {
public:
    unordered_map<int, int> res ;
    priority_queue<pair<int, int>> pq ; // {priority, -eventId}
    // take -(eventId) -> {1,3}, {1,2} -->> becomes {1,-2}, {1,-3} what we what
    // smallest eventId when priority are same
    EventManager(vector<vector<int>>& events) {
        for (auto &e : events) {
            int id = e[0] ;
            int prior = e[1] ;
            res[id] = prior ;
            pq.push({prior, -id}) ;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        res[eventId] = newPriority ;
        pq.push({newPriority, -eventId}) ; // lazy deletion
    }
    
    int pollHighest() {
        while (!pq.empty()) {
            auto [priority, negid] = pq.top() ;
            int id = -negid ; // reversing to original value

            // check if id and priority valid
            if (res[id] == priority) {
                pq.pop() ;
                res.erase(id) ; 
                return id ;
            }
            pq.pop() ; // outdated entry
        }
        return -1 ;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */