class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> res ;
        for (int x : nums) if (x >= 0) res.push_back(x) ;

        // normalize the k
        int n = res.size() ;
        // what if there is no positive number
        if (n > 0) k = k % n ;
        if (k == 0 || n == 0) return nums ;

        vector<int> temp ;
        for (int i = 0; i < k; i++) {
            temp.push_back(res[i]) ;
        }
        for (int i = k; i < n; i++) {
            res[i - k] = res[i] ;
        }
        for (int i = n - k; i < n; i++) {
            res[i] = temp[i + k - n] ; // i - (n - k) ;
        }
        // now assigning in original vector
        int p = 0 ;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {nums[i] = res[p] ; p++ ;}
        }
        return nums ;
    }
};