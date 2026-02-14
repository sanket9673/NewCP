class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()) ;
        int n = nums.size() ;
        if (n % k != 0) return false ;
        map<int, int> res ;
        for (int x : nums) res[x]++ ;
        // checking the groups if possible
        for (int num : nums) {
            if (res[num] == 0) continue ;

            // form group starting from num
            for (int j = 0; j < k; j++) {
                if (res.count(num + j) == 0) return false ;
                res[num + j]-- ;
            }
        }
        return true ;
    }
};