class Solution {
public:
    bool checkvow(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ;
    }
    int longestBeautifulSubstring(string word) {
        vector<char> chr ;
        vector<int> occ ;
        int count = 1 ;
        for (int i = 0; i < word.length() - 1; i++) {
            if (word[i] == word[i+1]) count++ ;
            else {
                chr.push_back(word[i]) ;
                occ.push_back(count) ;
                count = 1 ;
            }
        }
        chr.push_back(word[word.length() - 1]) ;
        occ.push_back(count) ; 

        stack<char> st ;
        int ans = 0, res = 0;
        for (int i = 0; i < chr.size(); i++) {
            if (st.empty()) {
                if (chr[i] == 'a') {
                    ans += occ[i] ;
                    st.push(chr[i]) ;
                }
                else continue ;
            }
            else {
                char c = st.top() ;
                char x = chr[i] ;
                if (c == 'a' && x == 'e') {st.push(x); ans += occ[i];}
                else if (c == 'e' && x == 'i') {st.push(x); ans += occ[i];}
                else if (c == 'i' && x == 'o') {st.push(x); ans += occ[i];}
                else if (c == 'o' && x == 'u') {
                    // final condition
                    st.push(x) ;
                    ans += occ[i];
                    res = max(res, ans) ;
                }
                else {
                    // resetinge are at whether 'a' or not
                    if (chr[i] == 'a') {
                    ans = 0 ;
                    while (!st.empty()) st.pop() ;

                    // checking the current element w
                        ans += occ[i] ;
                        st.push(chr[i]) ;
                    }
                }
            }
        }
        return res ;
    }
};
