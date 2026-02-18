class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long> suff ;
        int mn = INT_MAX ;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) suff.push_back(0) ;
            else {
                mn = min(mn, nums[i+1]) ;
                suff.push_back((long long)mn) ;
            }
        }
        // at the end we got the reversed suffix array
        reverse(suff.begin(), suff.end()) ;

        vector<long long> pref ;
        long long sum = 0 ;
        for (int x : nums) {
            sum += (long long)x ;
            pref.push_back((long long)sum) ;
        }
        long long score = pref[0] - suff[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            score = max(score, (long long)(pref[i] - suff[i])) ;
        }
        return score ;
    }
};