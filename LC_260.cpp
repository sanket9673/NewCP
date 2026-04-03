class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res ;
        int ans = 0 ;
        for (int num : nums) ans ^= num ;
        // all doubles are cancel out and we are left with x^y.
        int i ;
        for (i = 0; i < 32; i++) {
            int bit = 1 ;
            if (bit == ((ans >> i) & 1)) break ;
        }
        vector<int> b0, b1 ;
        int x = 0, y = 0 ;
        for (int num : nums) {
            if (((num >> i) & 1) == 0) x ^= num ;
            else y ^= num ;
        }
        res.push_back(x) ;
        res.push_back(y) ;
        return res ;
    }
};