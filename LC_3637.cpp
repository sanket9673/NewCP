class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        // approach with extra memory
        stack<int> st ;
        bool inc1 = false, inc2 = false, dec = false ;
        for (int x : nums) {
            if (st.empty()) st.push(x) ;
            else {
                // start of inc1 phase
                if (x > st.top() && !inc1 && !dec && !inc2) {
                    inc1 = true ;
                    st.push(x) ;
                } 
                // start of dec phase
                else if (x < st.top() && inc1 && !dec && !inc2) {
                    dec = true ;
                    st.push(x) ;
                }
                // start of inc2 phase
                else if (x > st.top() && dec && !inc2) {
                    inc2 = true ;
                    st.push(x) ;
                }
                // continue same phase (inc1 || inc2 || dec)
                else if (
                    (x > st.top() && inc1 && !dec) ||
                    (x < st.top() && inc1 && dec && !inc2) ||
                    (x > st.top() && inc1 && dec && inc2) 
                ) st.push(x) ;
                else return false ;
            }
        }
        return (inc1 && inc2 && dec) ;
    }
};