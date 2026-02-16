class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> rest ;
        for (int i = 0; i < words.size(); i++) {
            if (pattern.length() != words[i].length()) continue ;
            unordered_map<char, char> res ;
            unordered_set<char> ch ;
            bool check = true ;
            for (int j = 0; j < words[i].size(); j++) {
                if (res.count(pattern[j]) == 0) {
                    if (ch.count(words[i][j]) == 0) {
                        res[pattern[j]] = words[i][j] ;
                        ch.insert(words[i][j]) ;
                    }
                    else {check = false; continue ;}
                }
                else {
                    if (res[pattern[j]] != words[i][j]) {
                        check = false ;
                        continue ;
                    }
                }
            }
            if (check == true) rest.push_back(words[i]) ;
            
        }
        return rest ;
    }
};