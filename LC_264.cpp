class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res ;
        res.push_back(1) ;
        int tw = 0, thr = 0, fiv = 0 ;
        for (int i = 1; i <= n; i++) {
            int x1 = res[tw] * 2 ;
            int x3 = res[thr] * 3 ;
            int x5 = res[fiv] * 5 ;
            // append min element
            int mn = min({x1,x3,x5}) ;
            res.push_back(mn) ;
            // using all if and not if else as there can be number divisible by more than one divisor 
            // like 6 --> with 2 and with 3 also
            int last = res.back() ;
            if (last == x1) tw++ ;
            if (last == x3) thr++ ;
            if (last == x5) fiv++ ;
        }
        return res[n-1] ;
    }
};