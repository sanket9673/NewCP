class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], n = prices.size(), ans = 0 ;
        for (int i = 1; i < n; i++) {
            if (prices[i] < buy) {
                buy = prices[i] ;
            }
            ans = max(ans, prices[i] - buy) ;
        }
        return ans ;
    }
};