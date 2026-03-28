class Solution {
public:
    int minDeletions(string s) {
        sort(s.begin(), s.end()) ;
        int count = 1 ;
        vector<int> res ;
        // multiset<int, greater<int>> mp ;
        unordered_map<int, int> mp ;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i+1]) count++ ;
            else {
                // mp.insert(count) ;
                mp[count]++ ;
                res.push_back(count) ;
                count = 1 ;
            }
        }
        // mp.insert(count) ;
        mp[count]++ ;
        res.push_back(count) ;
        sort(res.begin(), res.end()) ;
        int n = res.size() ;

        int rest = 0 ;
        for (auto [x, y] : mp) {
            while (y > 1) {
                int num = x ;
                y-- ;
                while (num != 0 && mp[num] > 0) {
                    num-- ;
                    rest++ ;
                }
                if (num != 0) mp[num]++ ;
            }
            // int num = x ;
            // mp[num]-- ;
            // while (num != 0 && mp[num] > 0) {
            //     num-- ;
            //     rest++ ;
            // }
            // if (num != 0) mp[num]++ ;
        }
        return rest ;
    }
};