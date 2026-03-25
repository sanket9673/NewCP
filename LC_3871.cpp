class Solution {
public:
    long long countCommas(long long n) {
        long long start = 1000 ;
        int comma = 1 ;
        long long res = 0 ;
        while (start <= n) {
            // start = 1000 (first number with 1 comma)
            // next = 1000 * 1000 = 1,000,000 (next range) - 1 = 999,999
            long long end = start * 1000 - 1 ;
            
            // till where to go 
            long long actualend = min(n, end) ;
            // coount numbers
            long long numberscount = actualend - start + 1 ;
            res += numberscount * comma ;

            start *= 1000 ; // moving to next group 1,000 --> 1,000,000
            comma++ ;
        }
        return res ;
    }
};
