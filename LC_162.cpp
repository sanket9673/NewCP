class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1 ;
        while (l < r) {
            int mid = l + (r - l) / 2 ;
            // slope going up or down 
            // no need for "mid != nums.size() - 1"
            if (mid != nums.size() - 1 && nums[mid] > nums[mid + 1]) r = mid ;
            else l = mid + 1 ;
        }
        return l ;
    }
};