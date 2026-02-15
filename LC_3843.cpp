class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int, int> res ;
        map<int, int> unq ;
        for (int x : nums) res[x]++ ;
        for (auto [x, y] : res) {
            unq[y]++ ;
        }
        unordered_set<int> checked ;
        int ans = -1 ;
        for (int x : nums) {
            if (checked.count(x) == 0) {
                int ch = res[x] ;
                if (unq[ch] == 1) {
                    ans = x ;
                    return ans ;
                }
            }
        }
        return ans ;
    }
};