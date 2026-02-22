class Solution {
public:
    int binaryGap(int n) {
        string res = "" ;
        while (n > 0) {
            int bit = n & 1 ;
            res = to_string(bit) + res ;
            n >>= 1 ;
        }
        vector<int> rest ;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == '1') rest.push_back(i) ;
        }
        if (rest.size() == 1) return 0 ;
        int ans = 0; 
        for (int i = 0; i < rest.size() - 1; i++) {
            ans = max(ans, rest[i+1] - rest[i]) ;
        }
        
        return ans ;
    }
};