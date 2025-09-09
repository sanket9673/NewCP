class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // prefix + map
        // we need subarrays -> pref[i] - pref[j] = goal (sum from j+1 to i == goal)
        unordered_map<int, int> fq ;
        fq[0] = 1 ; // edge case 
        int res = 0, pref = 0 ;
        for (int i = 0; i < nums.size(); i++) {
            pref += nums[i] ;
            // pred[j] = pref[i] - goal
            if (fq.count(pref - goal) != 0) {
                res += fq[pref - goal] ;
            }
            fq[pref]++ ;
        }
        return res ;
    }
};