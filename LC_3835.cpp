class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        // we need to select data structure, where we can do the follow thing:
        // 1. push from front 
        // 2. pop from back
        // 3. get max/min in O(1) 
        // Data Structure Used : Monotonic Deque

        // EDGE CASE : K == 0
        // max == min and we return r ;
        int n = nums.size() ;
        // We store INDICES, not values
        int l = 0 ;
        long long ans = 0 ;
        deque<int> mxres ;
        deque<int> mnres ;
        for (int r = 0; r < n; r++) {
            // max deque stack
            while (!mxres.empty() && nums[mxres.back()] < nums[r]) {
                mxres.pop_back() ;
            }
            mxres.push_back(r) ;
            // min deque stack
            while (!mnres.empty() && nums[mnres.back()] > nums[r]) {
                mnres.pop_back() ;
            }
            mnres.push_back(r) ;
            
            // strink window if cost > k
            // front elements are max and min
            while ((long long)(nums[mxres.front()] - nums[mnres.front()]) * (r - l + 1) > k) {
                if (mxres.front() == l) mxres.pop_front() ;
                if (mnres.front() == l) mnres.pop_front() ;
                l++ ;
            }
            ans += (r - l + 1) ;
        }
        return ans ;
    }
};