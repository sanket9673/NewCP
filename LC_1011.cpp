class Solution {
public:
    bool canship(vector<int>& weights, int days, int w) {
        // Consider the least weight 'D' <= to ship all packages in D days
        int pack = 0, useday = 1 ;
        for (int x : weights) {
            if (x > w) return false ;
            if (pack + x <= w) pack += x ;
            else {
                useday++ ;
                pack = x ;
            }
        }
        return (useday <= days) ? true : false ;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // BINARY SERACH ON ANSWER
        // order in the weight array matters
        int low = *max_element(weights.begin(), weights.end()) ;
        int high = 0 ;
        for (int x : weights) high += x ;
        int result = INT_MAX ;
        while (low <= high) {
            int mid = low + (high - low) / 2 ;
            bool answer = canship(weights, days, mid) ;
            if (answer == true) {
                result = min(result, mid) ;
                // now we search is there any more small value possible ?
                high = mid - 1 ;
            }
            else low = mid + 1 ;
        }
        return result ;
    }
};