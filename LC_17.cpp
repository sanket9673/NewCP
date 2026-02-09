class Solution {
public:
    void backtrack(vector<string>& res, string& current, int id, string& digits, vector<string>& kp) {
        if (current.length() == digits.length()) {
            res.push_back(current) ;
            return ;
        }
        string l = kp[digits[id] - '0'] ;
        for (char c : l) {
            current += c ;
            backtrack(res, current, id + 1, digits, kp) ;
            current.pop_back() ;
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> kp = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;
        vector<string> res ;
        if (digits.empty() == true) return res ;
        string current = "" ;
        backtrack(res, current, 0, digits, kp) ;
        return res ;
    }
};