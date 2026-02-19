class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, one = 0 ;
        bool ch = false ;
        // zero single - no : zeros treated as one block and 1 can pass as block togethe of 0
        // 1 can cross 00 at one in one stepp therefore BLOCK CONSIDERED
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') {one++ ; ch = false ;}
            else {
                if (ch == false) {
                    ch = true ;
                    ans += one ;
                }
            }
        }
        return ans ;
    }
};