class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], n = prices.size(), ans = 0 ;
        for (int i = 1; i < n; i++) {
            // have to sell on same day that is at EOD
            if (prices[i] > prices[i - 1]) ans += (prices[i] - prices[i - 1]) ;
        }
        return ans ;
    }
};