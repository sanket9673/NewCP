class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // normal division wont work here
        bool sg = false ;
        long long n = (long long)numerator ;
        long long d = (long long)denominator ;
        if (n == 0) return "0" ;

        if (n < 0 && d < 0) {
            n = -n ;
            d = -d ;
        }
        if ((n < 0) ^ (d < 0)) {
            n = abs(n) ;
            d = abs(d) ;
            sg = true ;
        }

        long long intprt = n / d ;
        long long rem = n % d ;

        string res = to_string(intprt) ;
        if (rem == 0) {
            return (sg == true) ? "-" + res : res ;
        }
        // if rem not true add '.' and then multpy by 10 operations
        res += "." ;
        unordered_map<long long, int> mp ; // for storing the index whether already seen or not
        while (rem != 0) {
            if (mp.count(rem) != 0) {
                // inserting in the string
                res.insert(mp[rem], "(") ;
                res += ")" ;
                break ;
            }

            mp[rem] = res.length() ;
            // main part
            rem *= 10 ;
            intprt = rem / d ;
            res += to_string(intprt) ;
            rem = rem % d ;
        }
        return (sg == true) ? "-" + res : res ;
    }
};