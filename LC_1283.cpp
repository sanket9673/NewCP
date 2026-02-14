class Solution {
public:
    int result(vector<int>& nums, int& mid) {
        int sum = 0 ;
        for (int x : nums) {
            // sum += ceil(x/mid) ;
            sum += (x + mid - 1) / mid ; // more vaible to less prune to error
        }
        return sum ;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // binary search on answer
        // F F F F T T T T T T T T T ---> large divisor small sum (so we need to find the first T(smallest valid))
        sort(nums.begin(), nums.end()) ;
        int l = 1, r = nums.back() ;
        while (l < r) {
            int mid = l + (r - l) / 2 ;
            int res = result(nums, mid) ;
            if (res <= threshold) {
                r = mid ; // more small divisor possible --> T T T T (T) T T T T
            }
            else {
                l = mid + 1 ;
            }
        }
        return r ;
    }
};