class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()) ;
        int n = nums.size() ;
        // edge cases
        if (k == 0) return n ;
        for (int i = n - k - 1; i >= 0; i--) { // from n - k - 1 till 0
            if (nums[i+1] > nums[i]) return i+1 ;
        }
        return 0 ;
    }
};

// 1 2 2 3 4     k = 1
// 3  2  2  1  0

// 1 4 4 4       k = 2
// 1  0 0  0