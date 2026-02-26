class Solution {
public:
    int numSteps(string s) {
        int steps = 0 ;
        while (s != "1") {
            if (s.back() == '0') {
                s.pop_back() ;
            }
            else {
                bool carry = true ;
                string res = "0" ; // as it will always be 1 else we will land in if case
                for (int i = s.length() - 2; i >= 0; i--) {
                    if (s[i] == '0') {
                        if (carry == true) {res = '1' + res ; carry = false ;}
                        else res = '0' + res ;
                    }
                    else {
                        if (carry == true) {res = '0' + res; carry = true; }
                        else res = '1' + res ;
                    }
                }
                if (carry == true) res = '1' + res ; // 1 000 case
                s = res ;
            }
            steps++ ;
        }
        return steps ;
    }
};