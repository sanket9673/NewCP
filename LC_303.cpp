class NumArray {
public:
    vector<int> pref ;
    NumArray(vector<int>& nums) {
        int n = nums.size() ;
        pref.resize(n + 1, 0) ;
        // pref[0] = sum of 0 elements = 0
        // pref[1] = nums[0]
        // pref[2] = nums[0] + nums[1]
        // ...
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i] ;
        }
    }
    
    int sumRange(int left, int right) {
        // 👉 pref[right + 1]
        // = sum of elements from index 0 → right
        // 👉 pref[left]
        // = sum of elements from index 0 → left-1

        // (pref[0 → right]) - (pref[0 → left-1])
        // = sum[left → right]     

        return pref[right + 1] - pref[left] ;
    }
    
    // vector<int> res ;
    // NumArray(vector<int>& nums) {
    //     res = nums ;
    // }
    
    // int sumRange(int left, int right) {
    //     int sum = 0 ;
    //     for (int i = left; i <= right; i++) sum += res[i] ;
    //     return sum ;
    // }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

 