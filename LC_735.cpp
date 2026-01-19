class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st ;
        bool equal = false ;
        for (int as : asteroids) {
            if (st.empty()) st.push(as) ;
            else {
                while (!st.empty() && as < 0 && st.top() > 0) {
                    int x = abs(as) ;
                    int y = st.top() ;
                    if (x > y) st.pop() ;
                    else if (x == y) {
                        st.pop(); 
                        equal = true ;
                        break;  // 2. missed
                    }
                    else {equal = true; break;}  // 1. missed
                }
                if (equal == false) {   // 3.missed
                    st.push(as) ;
                }
                equal = false ;
            }
        }
        vector<int> res ;
        while (!st.empty()) {
            res.push_back(st.top()) ;
            st.pop() ;
        }
        reverse(res.begin(), res.end()) ;
        return res ;
    }
};