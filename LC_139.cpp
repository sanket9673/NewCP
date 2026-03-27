class Solution {
public:
    unordered_set<string> st ;
    unordered_map<int, bool> memo ; // saves the index result 
    // like : i(1) = true, i(5) = false --> helps save the time
    bool solve(string& s, int i) {
        if (i == s.length()) return true ;
        if (memo.count(i) != 0) return memo[i] ;

        string temp = "" ;
        for (int j = i; j < s.length(); j++) {
            temp += s[j] ;
            if (st.count(temp) != 0) {
                if (solve(s, j + 1)) return memo[i] = true ;
            }
        } 
        return memo[i] = false ;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // traveling and checking from last : greedy approach
        // greedy apporach misses some of the strings
        st = unordered_set<string>(wordDict.begin(), wordDict.end()) ;
        return solve(s, 0) ;
    }
};