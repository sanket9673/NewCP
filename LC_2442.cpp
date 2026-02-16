class Solution {
public:
    int rev(int& n) {
        int res = 0 ;
        while (n > 0) {
            int d = n % 10 ;
            n /= 10 ;
            res = res * 10 + d ;
        }
        return res ;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> res ;
        for (int n : nums) {
            res.insert(n) ;
            int revs = rev(n) ;
            res.insert(revs) ;
        }
        return res.size() ;
    }
};