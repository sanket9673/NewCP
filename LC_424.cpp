class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        // for all characters A-Z
        vector<int> c(26, 0) ;
        int p = 0, mx = 0, res = 0;
        for (int q = 0; q < n; q++) {
            c[s[q] - 'A']++ ;
            mx = max(mx, c[s[q] - 'A']) ; // take max count till now
    
            while ((q - p + 1) - mx > k) { // must be <= k to convert all charater to mx freq character
                c[s[p] - 'A']-- ;
                p++ ;
            }
            
            res = max(res, (q - p + 1)) ;
        }
        return res ;
    }
};