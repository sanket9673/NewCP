class Solution {
    public:
        int maxFrequencyElements(vector<int>& nums) {
            unordered_map<int, int> res ;
            int result = 0 ;
            for (int x : nums) res[x]++ ;
            int count = -1 ;
            for (auto &[key, val] : res) {
                count = max(val, count) ;
            }
    
            for (auto &[key, val] : res) {
                if (val == count) result += count ;
            }
            return result ;
        }
    };