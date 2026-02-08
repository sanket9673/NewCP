class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res ;
        int n = nums.size() ;
        // monotonic deque (we store only index)
        deque<int> qw ;
        for (int i = 0; i < k; i++) {
            while (!qw.empty() && nums[qw.back()] < nums[i]) {
                qw.pop_back() ;
            }
            qw.push_back(i) ;
        }
        res.push_back(nums[qw.front()]) ;
        int l = 0;
        for (int i = k; i < n; i++) {
            while (!qw.empty() && nums[qw.back()] < nums[i]) {
                qw.pop_back() ;
            }
            qw.push_back(i) ;

            if (qw.front() == l) qw.pop_front() ;
            l++ ;
            res.push_back(nums[qw.front()]) ;
        }
        return res ;
    }
};