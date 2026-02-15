class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        map<int, int> mp ;
        vector<int> res ;
        for (int x : bulbs) mp[x]++ ;
        for (auto [x, y] : mp) {
            if (y % 2 != 0) res.push_back(x) ;
        }
        return res ;
    }
};