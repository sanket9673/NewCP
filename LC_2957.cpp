class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int count = 0 ;
        for (int i = 0; i < word.length() - 1; i++) {
            int diff = abs(word[i] - word[i+1]) ;
            if (diff == 0 || diff == 1) {
                count++ ;
                i++ ;
            }
        }
        return count ;
    }
};