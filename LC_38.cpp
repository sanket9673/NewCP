class Solution {
public:
    string countAndSay(int n) {
        string res = "1" ;
        if (n == 1) return res ;
        // counting consecutive digits only and not all digits
        for (int i = 1; i < n; i++) {
            int count = 1 ;
            string rest = "" ;
            for (int j = 0; j < res.size(); j++) {
                // j + 1 avoid the buffer int this question
                if (j + 1 < res.size() && res[j] == res[j+1]) count++ ;
                else {
                    rest += to_string(count) ;
                    rest += res[j] ;
                    count = 1 ;
                }
            }
            res = rest ;
        }
        return res ;
    }
};