class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size() ;
        if (n <= 2) return n ;
        // every 2 numbers are in arithmetic form
        // left - arithmetic ending with i
        // right - arithmetic starting with i
        vector<int> left(n, 2), right(n, 2) ;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                left[i] = left[i - 1] + 1 ;
            }
        }
        for (int i = n - 3; i >= 0; i--) {
            if (nums[i + 1] - nums[i] == nums[i + 2] - nums[i + 1]) {
                right[i] = right[i + 1] + 1 ;
            }
        }
        // 3 cases : extend left[i-1]++ ; extend right[i+1]++ ; merging both 
        // third case : merging
        // a → x → b must follow SAME difference
        // So:
        // x - a = b - x
        // Solve it:
        // x = (a + b) / 2
        int ans = 0 ;
        for (int i = 0; i < n; i++) {
            ans = max(ans, max(left[i], right[i])) ; // no change
            if (i == 0) {
                ans = max(ans, 1 + right[i + 1]) ;
            }
            else if (i == n - 1) {
                ans = max(ans, 1 + left[i - 1]) ;
            }
            else {
                ans = max(ans, 1 + right[i+1]) ; // case1 : from left 
                ans = max(ans, 1 + left[i-1]) ; // case2 : from right
                // case3 : merge
                // x - a = b - x
                // Solve it:
                // x = (a + b) / 2
                if ((nums[i + 1] - nums[i - 1]) % 2 == 0) {
                    int req = (nums[i + 1] - nums[i - 1]) / 2 ;
                    int leftlen = 1, rightlen = 1 ; // start
                    // check whether left matched req
                    if (i >= 2 && nums[i - 1] - nums[i - 2] == req) {
                        leftlen = left[i - 1] ;
                        // tells can i extend left or keep the same length = 1
                    }
                    if (i < n - 2 && nums[i + 2] - nums[i + 1] == req) {
                        rightlen = right[i + 1] ;
                        // tells can i extend right or keep the same length = 1
                    }
                    // left block + fixed nums[i] + right block
                    ans = max(ans, 1 + leftlen + rightlen) ;
                }
            }
        }
        return ans ;
    }
};