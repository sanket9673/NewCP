class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        // each phase length must be >= 2
        int p = -1, q = -1, n = nums.size() ;
        // count represent comparion and not numbers
        // 1 < 2 -> count++
        int count1 = 0, count2 = 0, count3 = 0 ;
        // inc1
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) {
                count1++ ;
            }
            else {p = i-1; break ;}
        }
        if (p == -1) return false ;

        // dec
        for (int i = p+1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                count2++ ;
            }
            else {q = i-1; break ;}
        }
        if (q == -1) return false ;
        
        // inc2
        for (int i = q+1; i < n; i++) {
            if (nums[i] > nums[i-1]) count3++ ;
            else return false ;
        }

        return (count1 >= 1 && count2 >= 1 && count3 >= 1) ;

        // approach with extra memory
        // stack<int> st ;
        // bool inc1 = false, inc2 = false, dec = false ;
        // for (int x : nums) {
        //     if (st.empty()) st.push(x) ;
        //     else {
        //         // start of inc1 phase
        //         if (x > st.top() && !inc1 && !dec && !inc2) {
        //             inc1 = true ;
        //             st.push(x) ;
        //         } 
        //         // start of dec phase
        //         else if (x < st.top() && inc1 && !dec && !inc2) {
        //             dec = true ;
        //             st.push(x) ;
        //         }
        //         // start of inc2 phase
        //         else if (x > st.top() && dec && !inc2) {
        //             inc2 = true ;
        //             st.push(x) ;
        //         }
        //         // continue same phase (inc1 || inc2 || dec)
        //         else if (
        //             (x > st.top() && inc1 && !dec) ||
        //             (x < st.top() && inc1 && dec && !inc2) ||
        //             (x > st.top() && inc1 && dec && inc2) 
        //         ) st.push(x) ;
        //         else return false ;
        //     }
        // }
        // return (inc1 && inc2 && dec) ;
    }
};