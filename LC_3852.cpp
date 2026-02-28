class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> res ;
        for (int x : nums) res[x]++ ;

        
        int a = -1, b = -1 ;
        for (auto [x, y] : res) {
            if (a == -1) a = x ;
            else if (b == -1 && res[a] != res[x]) b = x ;

            if (a != -1 && b != -1) return {a, b} ;
        }
        return {-1, -1} ;
    }
};
