class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> res ;
        for (int i = 0; i < bills.size(); i++) {
            int x = bills[i] ;
            if (x == 5) res[x]++ ;
            else if (x == 10) {
                if (res[5] > 0) {res[5]-- ; res[x]++ ;}
                else return false ;
            }
            else {
                // more cases
                if (res[10] > 0 && res[5] > 0) { // 10 5
                    res[10]-- ;
                    res[5]-- ;
                }
                else if (res[5] >= 3) res[5] -= 3 ; // 5 5 5
                else return false ;
            }
        }
        return true ;
    }
};