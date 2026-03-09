class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long ans = 0 ;
        int n = nums.size() ;
        vector<long long> suff(n + 1, 1) ; // initial '1' 
        for (int i = n - 1; i >= 0; i--) {
            if (suff[i + 1] > LLONG_MAX / nums[i]) {
                suff[i] = LLONG_MAX ;
            }
            else suff[i] = suff[i + 1] * nums[i] ;
        }

        for (int i = 0; i < n; i++) {
            if (ans == suff[i + 1]) return i ;
            ans += nums[i] ;
        }
        return -1;

        // pref 2 3 5
        // prod 2 2 4
        // if (nums.size() == 1) return -1 ;

        // vector<long long> pref, prod ;
        // long long prd = 1, ans = 0 ;
        // int n = nums.size() ;
        // for (int i = 0; i < nums.size(); i++) {
        //     ans += (long long)nums[i] ;
        //     pref.push_back(ans) ;

        //     prd *= (long long)nums[n - i - 1] ;
        //     prod.push_back(prd) ;
        // }
        // reverse(prod.begin(), prod.end()) ;
        // n = pref.size() ;
        // for (int i = 0; i < pref.size(); i++) {

        // }
        // return -1 ;
    }
};