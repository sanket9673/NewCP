class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // tc : n * 2^n ||| s.c : 2^n * n
        // approach : bit masking
        vector<vector<int>> res ;
        vector<int> result ;
        int n = nums.size() ;
        int total = 1 << n ; // power : 2 ^ n 
        for (int mask = 0; mask < total; mask++) { // till 0 to 2^n - 1
            result.clear() ;
            for (int bit = 0; bit < n; bit++) {
                if (mask & (1 << bit)) result.push_back(nums[bit]) ;
            }
            res.push_back(result) ;
        } 
        return res ;
    }
};