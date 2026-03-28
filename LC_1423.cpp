class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // maxScore = totalSum - minSubarraySum(size = n - k)
        // [ LEFT PART ]   (removed middle)   [ RIGHT PART ]
        // what is remaining : front + back cards - maximum
        int n = cardPoints.size(), sum = 0, total = 0 ;
        
        for (int i = 0; i < n - k; i++) {
            sum += cardPoints[i] ;
        }
        for (int x : cardPoints) total += x ;

        if (n - k == 0) return total ;
        
        int res = sum, id = 0 ;
        for (int i = n-k; i < n; i++) {
            sum -= cardPoints[id++] ;
            sum += cardPoints[i] ;
            res = min(res, sum) ;
        }
        return total - res ;
    }
};