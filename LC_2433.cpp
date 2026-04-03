class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res ;
        int ans = pref[0] ;
        res.push_back(ans) ;
        for (int i = 1; i < pref.size(); i++) {
            // pref[i] = arr[0].......arr[i]
            // pref[i-1] = arr[0]..arr[i-1]
            // pref[i] ^ pref[i-1] ===== arr[i] ---> remains arr[i] after xor
            ans = pref[i] ^ pref[i-1];
            res.push_back(ans) ;
        } 
        return res ;
    }
};