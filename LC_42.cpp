class Solution {
public:
    int trap(vector<int>& height) {
        // Solution 3
        

        // // Solution 2 (tc : o(n) & sc: o(1))
        // // 2 pointer approach
        // int n = height.size(), left = 0, right = n - 1 ;
        // int lmax = 0, rmax = 0, water = 0;
        // while (left < right) {
        //     if (height[left] < height[right]) {
        //         if (height[left] > lmax) lmax = height[left] ;
        //         else water += lmax - height[left] ;
        //         left++ ;
        //     }
        //     else {
        //         if (height[right] > rmax) rmax = height[right];
        //         else water += rmax - height[right] ;
        //         right-- ;
        //     }
        // }
        // return water ;

        // Solution 1 (tc : O(n) & sc: o(2n))
        // // left-max and right-max > height[i]
        // // water[i] = min(left_max, right_max) - height[i]
        
        // int n = height.size(), water = 0 ;
        // vector<int> left(n, 0), right(n, 0) ;

        //  // build left max
        // left[0] = height[0];
        // for (int i = 1; i < n; i++) {
        //     left[i] = max(left[i - 1], height[i]);
        // }

        // // build right max
        // right[n - 1] = height[n - 1];
        // for (int i = n - 2; i >= 0; i--) {
        //     right[i] = max(right[i + 1], height[i]);
        // }

        // for (int i = 0; i < height.size(); i++) {
        //     if (min(left[i], right[i]) > height[i]) {
        //         water += min(left[i], right[i]) - height[i] ;
        //     }
        // }
        // return water ;
    }
};