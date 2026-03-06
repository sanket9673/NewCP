class Solution {
public:
    bool checkOnesSegment(string s) {
        if (s.length() == 1) return true ;
        unordered_map<char, int> res ;
        int count = 1 ;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i+1]) count++ ;
            else {
                if (s[i] == '0') res[s[i]] += count ;
                else {
                    if (res.count(s[i]) == 0) res[s[i]] = count ;
                    else return false ;
                }
                count = 1 ;
            }
        }
        if (count > 0) {
            if (s[s.length() - 1] == '0') res[s[s.length() - 1]] += count ;
            else {
                if (res.count(s[s.length() - 1]) == 0) res[s[s.length() - 1]] = count ;
                else return false ;
            }
        }
        return true ;
    }
};