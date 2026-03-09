class Solution {
public:
    string ss(int n) {
        string res = "" ;
        while (n > 0) {
            res = to_string(n & 1) + res ;
            n >>= 1 ;
        }
        return res ;
    }
    int minimumFlips(int n) {
        string res = ss(n) ;
        string smp = res ;
        reverse(smp.begin(), smp.end()) ;

        int ans = 0 ;
        for (int i = 0; i < res.length(); i++) {
            ans += (res[i] - '0') ^ (smp[i] - '0') ;
        }
        return ans ;
    }
};