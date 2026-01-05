class Solution {
public:
    bool canfinish(vector<int> piles, int h, int k) {
        int sum = 0 ;
        // speed = dis/hr(time)
        // hours needed = ceil [piles(dis)/k(speed) ]
        // total hrs = overall sum over piles
        // if total hrs <= k : able to finish in given time
        for (int x : piles) {
            // ceil 
            sum += ((x + k - 1) / k) ;
        }
        return (sum <= h) ? true : false ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // min k = 1 ; max k = max(piles)
        int low = 1, high = *max_element(piles.begin(), piles.end()) ;
        
        while (low < high) {
            int mid = low + (high - low) / 2 ;
            bool sample = canfinish(piles, h, mid) ;
            if (sample == true) high = mid ;
            else low = mid + 1 ;
        }
        return low ;
    }
};