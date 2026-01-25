class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        // Once the array is sorted, the minimum difference will always come from k consecutive elements.
        sort(nums.begin(), nums.end()) ;
        int n = nums.size(), res = INT_MAX ;
        if (n == 1) return 0 ;
        for (int i = 0; i+k-1 < n ; i++) {
            res = min(res, nums[i+k-1] - nums[i]) ;
        }
        return res ;
    }
};