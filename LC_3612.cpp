#include <iostream>
using namespace std ;

class Solution {
public:
    string processStr(string s) {
        // given s consists of lower and special charaters

        // handle edge cases like "#*%*#%#"
        string result = "" ;
        unordered_set<char> check = {'#', '%', '*'} ;
        for (char c : s) {
            if (!result.empty()) {
                if (c == '*') result.pop_back() ;
                else if (c == '#') result += result ;
                else if (c == '%') reverse(result.begin(), result.end()) ;
                else result += c ;
            }
            else {
                if (check.count(c) == 0) result += c ;
            }
        }
        return result ;
    }
};