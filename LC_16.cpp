class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()) ;
        map<int, int> mp ;
        int result = 0, diff1 = INT_MAX, diff2 = 0 ;
        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1, right = nums.size() - 1 ;
            while (left < right) {
                int total = nums[left] + nums[right] + nums[i] ;
                if (target == total) {
                    // result = total ;
                    // diff2 = 0 ;
                    // left++ ;
                    // right-- ;
                    // continue;
                    return total ;
                }
                else if (target < total) right-- ;
                else left++ ;
                diff2 = abs(total - target) ;
                if (diff2 <= diff1) {
                    result = total ;
                    diff1 = diff2 ;
                }
            }
        }
        return result ;
    }
};