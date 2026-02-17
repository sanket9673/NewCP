class Solution {
public:
    int countbits(int n) {
        int count = 0 ;
        while (n > 0) {
            count += (n & 1) ;
            n >>= 1 ;
        }
        return count ;
    }
    vector<int> countBits(int n) {
        vector<int> res ;
        for(int i = 0; i <= n; i++) {
            int count = countbits(i) ;
            res.push_back(count) ;
        }
        return res ;
    }
};