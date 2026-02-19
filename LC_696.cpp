class Solution {
public:
    int countBinarySubstrings(string s) {
        // pattern 0000111.... or 111000...
        // happens to group together
        vector<int> res ;
        int count = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i+1]) count++ ;
            else {
                res.push_back(count) ;
                count = 1 ;
            }
        }
        // pushing last count if exists
        res.push_back(count) ;
        
        // 0s 1s freq stored in order
        int ans = 0, n = res.size() ;
        for (int i = 0; i < res.size() - 1; i++) {
            ans += min(res[i], res[i+1]) ;
        }

        return ans ;
    }
};