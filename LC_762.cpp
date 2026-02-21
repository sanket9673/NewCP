class Solution {
public:
    bool prime(int& n) {
        if (n <= 1) return false ;
        if (n == 2) return true ;
        if (n % 2 == 0) return false ;
        for (int i = 3; i*i <= n; i+=2) {
            if (n % i == 0) return false ;
        }
        return true ;
    }
    int countPrimeSetBits(int left, int right) {
        // count set bits and check if its prime - yes : count++ else no
        int res = 0 ;
        for (int i = left; i <= right; i++) {
            int bits = 0 ;
            int n = i ;
            while (n > 0) {bits += n & 1; n >>= 1; }
            if (prime(bits) == true) res++ ;
        }
        return res ;
    }
};