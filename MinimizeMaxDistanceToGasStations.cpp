class Solution {
  public:
    bool canplace(vector<int>& stations, int k, double D) { // D not Integer
        // 6 decimal places -> double
        int used = 0 ;
        // station needed = partsDividedInto - 1
        // parts = ceil(gap/D)
        for (int i = 1; i < stations.size(); i++) {
            double gap = stations[i] - stations[i-1] ;
            // station needed -> floor(gap / D)
            used += (int)(gap/D) ;  // avoid float point precision error 
        }
        return used <= k ;
    }
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        // If i am allowed max of D distance
        // Can I place 'atmost k' stations to ensure all gaps  <= D
        
        // gap <= D -> no stations
        // gap > D -> need station
        
        // min gap --> 0
        // max gap --> max(of all gaps existed)
        double low = 0.0, high = 0.0 ;
        // max gap possible
        for (int i = 1; i < stations.size(); i++) {
            high = max(high, (double)(stations[i] - stations[i-1])) ;
        }
        
        // binary search of double (STANDARD FORM)
        // high - low <= allowed_error and here allowed error = 0.000001
        while (high - low > 1e-6) {
            double mid = (low + high) / 2.0 ;
            if (canplace(stations, K, mid) == true) high = mid ;
            else low = mid ;
        }
        return high ;
    }
};