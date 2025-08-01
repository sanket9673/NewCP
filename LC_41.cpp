#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // unordered_set<int> res ;
        // for (int num : nums) if (num >= 0) res.insert(num) ;
        // int result = 1 ;
        // while (res.count(result)) result++ ;
        // return result ;

        // INDEX PLACEMENT METHOD || CYCLE SORT

        // putting x at x-1 (placing the numbers)
        int n = nums.size() ;
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]) ;
            }
        }

        // step 2 (checking)
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) return i + 1 ;
        }

        return n + 1 ;
    }
};