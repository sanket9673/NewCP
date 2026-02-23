class Solution {
public:
    string removeKdigits(string num, int k) {
        // smallest number : monotonic stack (small ... large) monotinic increasing
        stack<char> st ;
        for (char c : num) {
            if (st.empty()) st.push(c) ;
            else {
                while (!st.empty() && (st.top() > c) && k > 0) {
                    st.pop() ;
                    k-- ;
                }
                st.push(c) ;
            } 
        }
        string res = "" ;
        while (!st.empty()) {
            char c = st.top() ;
            st.pop() ;
            // if (c != '0') {leading = false; res = c + res; }
            // else {
            //     if (leading == false) res = c + res ;
            // }
            res += c ;

            // below code gives TLE 
            // res = c + res ;
        }
        reverse(res.begin(), res.end()) ;

        // edge case
        while (k > 0 && !res.empty()) {res.pop_back(); k-- ;}
        if (res.empty()) return "0" ;

        // removing the leading zeros
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        res = res.substr(i);

        if (res.empty()) return "0";
        return res;
    }
};