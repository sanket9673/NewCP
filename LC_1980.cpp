class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // total number with n digits : 2^n
        unordered_set<string> res(nums.begin(), nums.end()) ;
        int n = nums[0].length() ;
        string ans = "" ;

        for (int i = 0; i < (1 << n); i++) {  // o to 2^n-1
            ans = "" ;
            for (int j = n - 1; j >= 0; j--) {
                ans += to_string((i >> j) & 1);
            }
            if (res.count(ans) == 0) break ;
        }
        return ans ;
    }
};