class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1 ;
        string res = "" ;
        while (n > 0) {
            int bit = n & 1 ;
            if (bit == 1) bit = 0 ;
            else bit = 1 ;
            res = to_string(bit) + res ;
            n >>= 1 ;
        }
        int ans = 0 ;
        for (int i = 0; i < res.size(); i++) {
            ans += ((res[res.length() - 1 - i] - '0') * pow(2, i)) ;
        }
        return ans ;
    }
};