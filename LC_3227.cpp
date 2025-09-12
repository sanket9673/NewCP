class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> chk = {'a', 'e', 'i', 'o', 'u'} ;
        int vcount = 0 ;
        for (char c : s) {
            if (chk.count(c) != 0) vcount++ ;
        }
        return (vcount > 0) ? true : false ;
    }
};