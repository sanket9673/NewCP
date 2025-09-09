class Solution {
public:
    // IDEA -- SUBARRAY(count <= k) - SUBARRAY(count <= k-1) = SUBARRAY(count == k)
    int search(vector<int>& nums, int k) {
        if (k < 0) return 0 ;
        int l = 0, r = 0, count = 0, res = 0 ;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) count++ ;
            while (count > k) {
                if (nums[l] % 2 != 0) count-- ;
                l++ ;
            }
            res += (r - l + 1) ;
        }
        return res ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int result = search(nums, k) - search(nums, k - 1) ;
        return result ;
    }
};