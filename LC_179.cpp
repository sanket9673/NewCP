class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> res ;
        // first convert the int to string
        for (int x : nums) {
            res.push_back(to_string(x)) ;
        }

        // make custom operator for checking ab and ba
        // a = 33 b = 30 --> ab(3033) < ba(3303)
        sort(res.begin(), res.end(), [](string &a, string &b) {
            return a + b > b + a ;
        }) ;
        
        if (res[0] == "0") {
            return "0" ;
        }

        string ans = "" ; 
        for (string x : res) ans += x ;
        return ans ;
    }
};