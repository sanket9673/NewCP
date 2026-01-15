class Solution {
public:
    long long countPairs(vector<string>& words) {
        long long res = 0 ;
        vector<int> diff ;
        map<vector<int>, long long> result ;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 1 ; j < words[i].length(); j++) {
                // normaliziing to resolve the -ve value
                int ans = (words[i][j] - words[i][j-1] + 26) % 26 ;
                diff.push_back(ans) ;
            }
            result[diff] += 1 ;
            diff.clear() ;
        }
        for (const auto&[ft, sc] : result) {
            // pairs formed is -> n*(n-1)/2
            if (sc > 1) res += sc * (sc - 1) / 2 ;
        }
        return res ;
    }
};