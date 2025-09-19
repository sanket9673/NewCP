class Solution {
    public:
        long long countbits(long long n) {
            // trick
            // n = 12 → (binary: 1100)
            // n - 1 = 11 → (binary: 1011)
            // n & (n-1) = 1000 (binary)
            long long count = 0 ;
            while (n) {
                n &= (n - 1) ;
                count++ ;
            }
            return count ;
        }
        long long countExcellentPairs(vector<int>& nums, int k) {
            //idea
            // make pair of {bits, (number having that bits)}
            // check for low bits(AND) & many bits(OR)
            // 2 & 3 === AND(2) & OR(3) -- IDEA (thats range)
            long long result = 0 ;
            unordered_set<int> smp(nums.begin(), nums.end()) ;
            unordered_map<int, int> res ;
            for (auto val : smp) {
                int btscount = countbits(val) ;
                res[btscount]++ ;
            }
            for (auto [bits, val] : res) {
                if (bits * 2 >= k) result += (val * val) ;
                for (auto [newbits, newval] : res) {
                    if (bits != newbits) {
                        int x = bits + newbits ;
                        if (x >= k) result += (res[bits] * res[newbits]) ;N
                    }
                }
                // int x = abs(k - bits) ;
                // if (res.count(x) != 0) {
                //     result += (res[bits] * res[x]) ;
                // }
            }
            return result ;
        }
    };