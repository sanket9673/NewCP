class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<int, int> freq ;
        freq[0] = 1 ;
        long ans = 0 ;
        int pref = 0 ;
        for (int x : arr) {
            pref ^= x ;
            // prefix xor computed
            
            // what we want
            int need = pref ^ k ;
            
            // check if there in map
            if (freq.count(need) != 0) ans += freq[need] ;
            
            // store the prefix 
            freq[pref]++ ;
        }
        return ans ;
        // GOAL : pref[l-1] ^ pref[r] = k ---> finding (l, r) pairs
        //        till l-1 ^ till l-1   becomes zero ---> x ^ x = 0
        
        
        
        // INCORRECT (here we should not do SLIDING WINDOW)
        // int l = 0, result = 0, ans = 0;
        // for (int i = 0; i < pref.size(); i++) {
        //     result ^= pref[i] ;
        //     if (result == k) ans++ ;
        //     else if (result > k) {
        //         while (l <= i) {
        //             result ^= pref[l] ;
        //             l++ ;
        //         }
        //     }
        // }
        return ans ;
    }
};