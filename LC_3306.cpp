class Solution {
public:
    // exactly k = atmost(k) - atmost(k - 1)   ----> main idea
    bool checkvow(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ;
    }
    long long atmostk(string &word, int k) {
        if (k < 0) return 0 ;
        vector<int> last(5, -1) ;
        int l = 0, cons = 0 ;
        long long ans = 0 ;
        for (int r = 0; r < word.length(); r++) {
            if (checkvow(word[r])) {
                if (word[r] == 'a') last[0] = r ;
                else if (word[r] == 'e') last[1] = r ;
                else if (word[r] == 'i') last[2] = r;
                else if (word[r] == 'o') last[3] = r ;
                else last[4] = r ;
            }
            else cons++ ;

            while (cons > k) {
                if (!checkvow(word[l])) cons-- ;
                l++ ;
            }

            int mn = *min_element(last.begin(), last.end()) ;
            if (mn >= l) {
                ans += (mn - l + 1) ;
            }
        }
        return ans ;
    }
    long long countOfSubstrings(string word, int k) {
        return atmostk(word, k) - atmostk(word, k - 1) ;
    }
};