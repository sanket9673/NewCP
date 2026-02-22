class Solution {
public:
    string compressedString(string word) {
        vector<int> ss(256, 0) ;
        string res = "" ;
        for (int i = 0; i < word.length(); i++) {
            int id = word[i] - 'a' ;
            ss[id]++ ;
            if ((word[i] - 'a' != word[i+1] - 'a')|| ss[id] == 9) {
                res += to_string(ss[id]) + word[i] ;
                ss[id] = 0 ;
            }
        }
        return res ;
    }
};