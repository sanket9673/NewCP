class Solution {
public:
    int reverse(int x) {
        long long n = x ;
        int neg = 1 ;
        if (n < 0) {n = -n ; neg = -1;}
        long long res = 0 ;
        while (n > 0) {
            long long d = n % 10 ;
            n /= 10 ;
            res = res * 10 + d ;
        }
        res = neg * res ;
        if (res <= INT_MIN || res >= INT_MAX) return 0 ;
        return (int)res ;
    }
};