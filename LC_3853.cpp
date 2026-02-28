class Solution {
public:
    string mergeCharacters(string s, int k) {
        string ans = "" ;
        int i = 0 ;
        bool carry = true ;
        while (carry == true) {
            bool merged = false ;
            for (int j = i + 1; j < s.length(); j++) {
                if (s[i] == s[j] && (j - i) <= k) {
                    string lft = s.substr(0, j) ;
                    string rgt = s.substr(j + 1) ;
                    s = lft + rgt ;
                    i = 0 ;
                    merged = true ;
                    break ;
                }
            }
            if (merged == false) i++ ;
            if (i == s.length()) break ;
        }
        
        return s ;
    }
};