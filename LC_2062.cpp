class Solution {
public:
    bool checkvow(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ;
    }
    int atmost(string& word, int k) {
        int l = 0, ans = 0 ;
        unordered_map<char, int> res ;
        for (int r = 0; r < word.length(); r++) {
            if (!checkvow(word[r])) {
                l = r + 1 ;
                res.clear() ;
                continue ;
            }

            res[word[r]]++ ;

            while (res.size() > k) {
                res[word[l]]-- ;
                if (res[word[l]] == 0) res.erase(word[l]) ;
                l++ ;
            }

            ans += (r - l + 1) ;
        }
        return ans ;
    }
    // substring with exact k : atmost(k) - atmost(k-1)
    int countVowelSubstrings(string word) {
        return atmost(word, 5) - atmost(word, 4) ;
    }
};