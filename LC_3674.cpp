class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> res(nums.begin(), nums.end()) ;
        return (res.size() == 1) ? 0 : 1 ;
    }
};