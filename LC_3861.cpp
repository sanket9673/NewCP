class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int id = -1, ans = INT_MAX ;
        for (int i = 0; i < capacity.size(); i++) {
            if (capacity[i] == itemSize) return i ;
            else if (capacity[i] > itemSize) {
                if (ans > capacity[i]) {
                    ans = capacity[i] ;
                    id = i ;
                }
            }
        }
        return id ;
    }
};