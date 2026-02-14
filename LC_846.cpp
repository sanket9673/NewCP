class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size(), k = groupSize ;
        if (n % groupSize != 0) return false ;
        map<int, int> res ;
        for (int num : hand) res[num]++ ;
        sort(hand.begin(), hand.end()) ;
        for (int x : hand) {
            if (res[x] == 0) continue ;
            for (int i = 0; i < k; i++) {
                if (res[x + i] == 0) return false ;
                res[x + i]-- ;
            }
        }
        return true ;
    }
};