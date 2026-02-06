class Solution {
public:
    int solve(string& s, bool& numstart, bool& sig, int& neg, int i, long long& num) {
        //base
        if (i == s.length() || isspace(s[i])) { // out of index || space detected
            num = num * neg ;
            if (num > INT_MAX) return INT_MAX ;
            else if (num < INT_MIN) return INT_MIN ;
            else return (int)num ;
        }
        unsigned char x = s[i] ;
        if (isdigit(x)) {
            if (numstart == false) numstart = true ; // number started
            if (sig == false) sig = true ; // no need of sign
            int d = x - '0' ;
            if (num > (INT_MAX - d) / 10) {
                return (neg == -1) ? INT_MIN : INT_MAX ;
            }
            else num = num * 10 + d ;
            return solve(s, numstart, sig, neg, i+1, num) ;
        }
        else {
            if (x == '-' && sig == false && numstart == false) {
                neg = -1 ;
                sig = true ;
                return solve(s, numstart, sig, neg, i+1, num) ;
            }
            else if (x == '+' && sig == false && numstart == false) {
                neg = 1 ;
                sig = true ;
                return solve(s, numstart, sig, neg, i+1, num) ;
            }
            else {
                num = num * neg ;
                if (num > INT_MAX) return INT_MAX ;
                else if (num < INT_MIN) return INT_MIN ;
                else return (int)num ;
            }
        }
        num = num * neg ;
        if (num > INT_MAX) return INT_MAX ;
        else if (num < INT_MIN) return INT_MIN ;
        else return (int)num ;
    }
    int myAtoi(string s) {
        int id = 0 ;
        while (isspace(s[id])) id++ ;
        if (id + 1 < s.size()) s = s.substr(id) ; // remove spaces before and then subtring passed
        long long num = 0;
        bool numstart = false, sig = false ;
        int neg = 1 ;
        return solve(s, numstart, sig, neg, 0, num) ;
    }
};