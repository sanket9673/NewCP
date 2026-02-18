class Solution {
public:
    bool hasAlternatingBits(int n) {
        string res = "" ;
        while (n > 0) {
            if (n % 2 == 0) res += '1' ;
            else res += '0' ;
            n = n/2 ; 
        }
        if (res.size() < 2) return true ;
        for (int i = 0; i < res.size() - 1; i++) {
            if (res[i] == res[i+1]) return false ;
        }
        return true ;
    }
};