class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long sum = 0, result = 0, n = balance.size(), idx = 0;
        bool neg = false;
        for (int i = 0; i < balance.size(); i++) {
            if (balance[i] < 0) {neg = true ; idx = i ;}
            sum += balance[i] ;
        }
        
        if (sum < 0) return -1 ;
        if (neg == false) return 0 ;
        int left = 0, right = 0 ;
        int steps = 1 ;
        long long x = balance[idx] ;
        while (x < 0) {
            left = (idx - steps + n) % n;   //offsetting
            right = (idx + steps) % n ;
            if (x < 0) {
                // issue : min(long long, int)
                // int ans = min(abs(x), balance[left]) ;
                long long ans = min(abs(x), (long long)balance[left]) ;
                x += ans;  // not x -= ans as x is negative
                result += (ans * steps) ;
            }
            if (x < 0) {
                // same issue of min
                // int bns = min(abs(x), balance[right]) ;
                long long bns = min(abs(x), (long long)balance[right]) ;
                x += bns ;
                result += (bns * steps) ;
            } 
            steps++ ;
        }
        return result ;
    }
};