class Solution {
public:
    const int MOD = 1e9 + 7 ;
    int numSub(string s) {
        // total substring : n * ( n + 1) / 2
        stack<int> st ;
        int count = 1 ;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '1') {
                if (s[i] == s[i+1]) count++ ;
                else {
                    st.push(count) ;
                    count = 1 ;
                }
            }
        }
        if (s[s.length() - 1] == '1') st.push(count) ;

        long long res = 0 ;
        while (!st.empty()) {
            long long n = (long long)st.top() ;
            cout << n << endl ;
            st.pop() ;
            res = (res + ((n * (n + 1)) / 2) % MOD) % MOD;
        }
        return (int)res ;
    }
};