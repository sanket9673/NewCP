class Solution {
public:
    void invert(string& res) {
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == '1') res[i] = '0' ;
            else res[i] = '1' ; 
        }
    }
    char findKthBit(int n, int k) {
        string res = "0" ;
        if (k - 1 == 0) return res[res.size() - 1] ;
        for (int i = 1; i < n; i++) {
            string rev = res ;
            reverse(rev.begin(), rev.end()) ;
            res = res + "1" ;
            invert(rev) ;
            res += rev ;
            if (res.size() >= k) return res[k - 1] ;
        }
        return res[0] ;
    } 
};