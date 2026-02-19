class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> res ; // storing indices and not the actual value for result generation
        for (int i = 0; i < s.length(); i++) {
            if (!isalpha(s[i])) {
                if (res.empty()) res.push(i) ; // saving indices
                else {
                    if (s[res.top()] == '(' && s[i] == ')') res.pop() ;
                    else res.push(i) ;
                }
            }
        }
        //storing those indices which are invalid
        unordered_set<int> ind ;
        while (!res.empty()) {
            int id = res.top() ;
            res.pop() ;
            ind.insert(id) ;
        }
        string result = "" ;
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) result += s[i] ;
            else {
                if (ind.count(i) == 0) result += s[i] ;
            }
        }
        return result ;
    }
};