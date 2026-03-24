class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        // atleast k
        unordered_map<int, long long> res ;
        long long pairs = 0, ans = 0 ;
        int l = 0, n = nums.size() ;
        for (int r = 0; r < n; r++) {
            pairs += res[nums[r]] ;
            res[nums[r]]++ ;
            while (pairs >= k) {
                ans += (n - r) ; // all valid from r r+1 .......
                res[nums[l]]-- ;
                pairs -= res[nums[l]] ;
                l++ ;
            }
        }
        return ans ;
    }
};