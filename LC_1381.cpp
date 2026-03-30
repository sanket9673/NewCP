class CustomStack {
public:
    vector<int> res ;
    int mxsize ;
    CustomStack(int maxSize) {
        mxsize = maxSize ;
    }
    
    void push(int x) {
        if (res.size() < mxsize) res.push_back(x) ;
    }
    
    int pop() {
        if (res.empty()) return -1 ;
        int ele = res.back() ;
        res.pop_back() ;
        return ele ;
    }
    
    void increment(int k, int val) {
        int sz = min((int)res.size(), k) ;
        for (int i = 0; i < sz; i++) res[i] += val ;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */