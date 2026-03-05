class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u'} ;
        vector<pair<int, int>> arr ;

        int c = 0, v = 0 ;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i] ;
            if (vow.count(ch) != 0) v++ ;
            else c++ ;
            arr.push_back({v, c}) ;
        }
        int res = 0 ;
        for (int i = 0; i < arr.size(); i++) {
            int a = arr[i].first ;
            int b = arr[i].second ;
            if (a == b && (a * b) % k == 0) res++ ;
            for (int j = i + 1; j < arr.size(); j++) {
                int x = arr[j].first ;
                int y = arr[j].second ;
                x = x - a ;
                y = y - b ;
                if (x == y && ((x * y) % k == 0)) res++ ;
            }
        }
        return res ;
    }
};