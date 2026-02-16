class Solution {
public:
    int longestContinuousSubstring(string s) {
        int count = 1, res = 1 ;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i+1] - s[i] == 1) {
                count++ ;
            }
            else {
                res = max(count, res) ;
                count = 1 ;
            }
        }
        res = max(count, res) ;
        return res ;
    }
};