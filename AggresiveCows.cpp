class Solution {
  public:
    bool canfit(vector<int>& stalls, int k, int dist) {
        int cow = 1, prev = stalls[0] ;
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - prev >= dist) {
                prev = stalls[i] ;
                cow++ ;
                if (cow == k) return true ;
            }
        }
        return false ;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        // CORE IDEA
        // Can I place cows such that each cow is at least D meters apart
        
        int result = 0 ;
        sort(stalls.begin(), stalls.end()) ;
        int low = 1, high = stalls.back() - stalls[0] ;
        while (low <= high) {
            int mid = low + (high - low) / 2 ;
            bool fit = canfit(stalls, k , mid) ;
            if (fit == true) {
                result = max(result, mid) ;
                // if dist found, we should try bigger distance
                low = mid + 1 ;
            }
            else high = mid - 1 ;
        }
        return result ;
    }
};