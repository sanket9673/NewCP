class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int sz = buildings.size() ;
        map<int, int> xmin, xmax, ymin, ymax ;
        int x = 0, y = 0, result = 0 ;
        for (int i = 0; i < sz; i++) {
            x = buildings[i][0], y = buildings[i][1] ;
            if (xmin.count(x) != 0) {
                xmin[x] = min(xmin[x], y) ;
                xmax[x] = max(xmax[x], y) ;
            } else xmin[x] = xmax[x] = y ;

            if (ymin.count(y) != 0) {
                ymin[y] = min(ymin[y], x) ;
                ymax[y] = max(ymax[y], x) ;
            } else ymin[y] = ymax[y] = x ;
            
            // WRONG
            // if (xmin.count(x) != 0 && xmax.count(x) != 0 && ymin.count(y) != 0 && ymax.count(y) != 0) {
            //     xmin[x] = min(xmin[x], y) ;
            //     xmax[x] = max(xmax[x], y) ;
            //     ymin[y] = min(ymin[y], x) ;
            //     ymax[y] = max(ymax[y], x) ;
            // }
            // else {
            //     xmin[x] = y;
            //     xmax[x] = y ;
            //     ymin[y] = x ;
            //     ymax[y] = x ; 
            // }
        }
        for (int i = 0; i < sz; i++) {
            x = buildings[i][0], y = buildings[i][1] ;
            if ((ymin[y] < x && x < ymax[y]) && (xmin[x] < y && y < xmax[x])) result++ ; 
        }
        return result ;
    }
};