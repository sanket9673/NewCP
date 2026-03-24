class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end()) ;
        string res = "" ;
        int n = strs.size() ;
        for (int i = 0; i < strs[0].length(); i++) {
            if (strs[0][i] == strs[n-1][i]) res += strs[0][i] ;
            else return res ;
        }
        return res ;
    }
};