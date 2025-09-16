class Solution {
public:
    string removeDuplicates(string s, int k) {
        // idea : using stack and inside making pair{character, count}
        // count stores continuous occurence
        stack<pair<char,int>> st ;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i] ;
            if (st.empty() || st.top().first != c) {
                st.push({c, 1}) ;
            }
            else {
                st.top().second += 1 ;
                if (st.top().second == k) st.pop() ;
            }
        }
        string res = "" ;
        while (!st.empty()) {
            int count = st.top().second ;
            while (count--) res += st.top().first ;
            st.pop() ;
        }
        reverse(res.begin(), res.end()) ;
        return res ;
    }
};