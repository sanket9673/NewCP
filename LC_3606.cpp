class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        // to check alphanumeric : isalnum()
        vector<string> res ;
        const regex pattern("^[a-zA-Z0-9_]*") ;
        map<string, vector<string>> mp ;
        for (int i = 0; i < code.size(); i++) {
            if (isActive[i] == true) {
                if (code[i].size() > 0 && regex_match(code[i], pattern)) mp[businessLine[i]].push_back(code[i]) ;
            }
        }
        for (auto &p : mp) sort(p.second.begin(), p.second.end()) ;
        vector<string> business = {"electronics", "grocery", "pharmacy", "restaurant"} ;
        for (string s : business) {
            if (mp.count(s)) res.insert(res.end(), mp[s].begin(), mp[s].end()) ;
        }
        return res ;
    }
};