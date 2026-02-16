class Solution {
public:
    int vowelConsonantScore(string s) {
        unordered_set<int> vow = {'a','e','i','o','u'} ;
        int v = 0, c = 0;
        for (char x : s) {
            if (isalpha(x)) {
                if (vow.count(x) != 0) v++ ;
                else c++ ;
            }
        }
        return (c > 0) ? (floor(v/c)) : 0 ;
    }
};