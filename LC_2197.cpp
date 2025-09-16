class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st ;
        for (int x : nums){
            long long num = x ;
            while (!st.empty()) {
                long long y = st.back() ; // vector last ele ;
                long long cal_gcd = gcd(num, y) ;
                if (cal_gcd == 1) break ;
                st.pop_back() ;
                num = lcm(num, y) ;
            } 
            st.push_back(num) ;
        }

        // covert back to int
        vector<int> res ;
        for (long long number : st) {
            int newnumber = (int)number ;
            res.push_back(newnumber) ;
        }
        return res ;


        // CORRECT APPROACH (BUT WRONG SOLN -- SUPER QUADRATIC)
        // vector<int> res ;
        // if (nums.size() < 2) return nums ;
        // int oldsz = -1 ;
        // res.insert(res.end(), nums.begin(), nums.end()) ;
        // while (true) {
        //     stack<int> st ;
        //     int num = res[0] ;
        //     st.push(num) ;
        //     for (int i = 1; i < res.size(); i++) {
        //         int x = st.top() ;
        //         if (gcd(x,res[i]) > 1) {
        //             st.pop() ;
        //             st.push(lcm(x, res[i])) ;
        //         }
        //         else st.push(res[i])  ;

        //         // clear res to add new ele
        //         res.clear() ;
        //         int newsz = st.size() ;
        //         // ele added to vector
        //         while (!st.empty()) {
        //             int ele = st.top() ;
        //             st.pop() ;
        //             res.push_back(ele) ;
        //         }
        //         reverse(res.begin(), res.end()) ;

        //         // stopping condition
        //         if (oldsz != -1 && oldsz >= newsz) break ;
        //         else oldsz = newsz ;
        //     }
        // }
        // return res ;
    }
};