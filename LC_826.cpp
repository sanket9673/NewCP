class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> res ;
        for (int i = 0; i < difficulty.size(); i++) {
            res.push_back({difficulty[i], profit[i]}) ;
        }
        sort(res.begin(), res.end()) ;

        int bestPay = 0, k = 0, finalprofit = 0 ;
        // best = max(best, jobs[j].second) --> WE NEED TO TAKE MAX PROFIT FOR EACH WORKER
        sort(worker.begin(), worker.end()) ;
        for (int i = 0; i < worker.size(); i++) {
            while (k < res.size() && worker[i] >= res[k].first) {
                bestPay = max(bestPay, res[k].second) ;
                k++ ;
            }
            finalprofit += bestPay ; // particular worker MAX contribution
        }

        return finalprofit ;
    }
};