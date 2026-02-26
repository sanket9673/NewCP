class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int mx = maxDoubles ;
        if (mx == 0) return target - 1 ;
        int steps = 0 ;
        while (target != 1) {
            if (mx > 0 && target % 2 == 0) {target /= 2 ; mx-- ;}
            else target-- ;
            steps++ ;
        }
        return steps ;
    }
};