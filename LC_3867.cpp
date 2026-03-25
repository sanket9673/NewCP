class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a ;
        return gcd(b, a % b) ;
    }
    long long gcdSum(vector<int>& nums) {
        long long ans = 0 ;
        vector<int> res ;
        int mx = INT_MIN, n = nums.size() ;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]) ;
            int x = gcd(nums[i], mx) ;
            res.push_back(x) ;
        }
        sort(res.begin(), res.end()) ;
        int l = 0, r = res.size() - 1 ;
        while (l < r) {
            ans += gcd(res[l], res[r]) ;
            l++ ;
            r-- ;
        }
        return ans ;
    }
};