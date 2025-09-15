class Solution {
    public:
        int canBeTypedWords(string text, string brokenLetters) {
            unordered_set<char> letters ;
            for (char c : brokenLetters) letters.insert(c) ;
            int result = 0 ;
            bool fnd = false ;
            for (int i = 0; i < text.length(); i++) {
                if (letters.count(text[i]) != 0) fnd = true ;
                if (isspace(text[i])) {
                    if (fnd == false) result++ ;
                    else {fnd = false ;}
                }
            }
            if (fnd == false) result++ ; // last case to be handled
            return result ;
        }
    };