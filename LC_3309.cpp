class Solution {
public:
    int bitslength(int n) {
        int bits = 0 ;
        while (n > 0) {
            bits++ ;
            n >>= 1 ;
        }
        return bits ;
    }
    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end()) ;
        int res = -1 ;

        // for first array before next permutation or else use : DO-WHILE LOOP
        int curr = nums[0] ;
            for (int i = 1; i < 3; i++) {
                int bits = bitslength(nums[i]) ;
                curr = ((curr << bits) | nums[i]) ;
            }
        res = max(curr, res) ;

        while (next_permutation(nums.begin(), nums.end())) {
            curr = nums[0] ;
            for (int i = 1; i < 3; i++) {
                int bits = bitslength(nums[i]) ;
                curr = ((curr << bits) | nums[i]) ;
            }
            res = max(curr, res) ;
        }
        return res ;
    }
};