class Solution {
public:
    bool minimumY(vector<vector<int>>& squares, double area, double mid) {
        double samplearea = 0.0 ;
        for (int i = 0 ; i < squares.size(); i++) {
            if (squares[i][1] <= mid) {
                samplearea += (double)squares[i][2]*(min(mid-(double)squares[i][1], (double)squares[i][2])) ;
            }
        }
        return samplearea >= area ;
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX, high = 0.0, area = 0.0 ;
        for (int i = 0 ; i < squares.size(); i++) {
            low = min((double)squares[i][1], low) ;
            high = max((double)squares[i][1] + (double)squares[i][2], high) ;
            area += ((double)squares[i][2]*(double)squares[i][2]) ;
        }
        while (high - low > 1e-5) {
            double mid = (high + low) / 2.0 ;
            if (minimumY(squares, area/2.0, mid) == true) {
                high = mid ;
            }
            else low = mid ;
        }
        return low ;
    }
};