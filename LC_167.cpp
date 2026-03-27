class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size() ;
        for (int i = n - 1; i >= 1; i--) {
            int x = target - numbers[i] ;
            int l = 0, r = i - 1 ;
            while (l <= r) {
                int mid = l + (r - l) / 2 ;
                if (numbers[mid] == x) return {mid + 1, i + 1} ;
                else if (numbers[mid] < x) l = mid + 1 ;
                else r = mid - 1 ;
            }
        } 
        return {0, 0} ;
    }
};