class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // using bitmask and generating all 2^k strings is vague : VERY HUGE: MLE

        // idea : generate all possible k unqiue length string from s 
        // AND check if count == 2^k ? true : false 

        // UNIQUE STRINGS OF LENGTH K
        unordered_set<string> res ;
        for (int i = 0; i + k <= s.length(); i++) {
            string chk = s.substr(i, k); // substr(start index, length)
            res.insert(chk) ;
        }
        return (res.size() == pow(2, k)) ;
    }
};