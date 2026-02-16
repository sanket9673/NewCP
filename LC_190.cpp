class Solution {
public:
    int reverseBits(int n) {
        // inbuilt bitset<32>(decimal number)
        bitset<32> bnary(n) ;
        string bits = bnary.to_string() ;
        reverse(bits.begin(), bits.end()) ;
        bitset<32> ans(bits) ;
        return (int)ans.to_ulong() ;
    }
};