class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()) ;
        int n = nums.size() ;
        int l = 0, r = n-1 ;
        int ans = INT_MIN ;
        while (l < r) {
            ans = max(ans, nums[l] + nums[r]) ;
            l++ ;
            r-- ;
        }
        return ans ;
    }
};