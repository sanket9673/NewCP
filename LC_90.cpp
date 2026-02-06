class Solution {
public:
    void setss(int id, vector<int>& nums, vector<int>& arr, set<vector<int>>& st) {
        if (id == nums.size()) {
            st.insert(arr) ;
            return ;
        }
        // take
        arr.push_back(nums[id]) ;
        setss(id + 1, nums, arr, st) ;
        // not take
        arr.pop_back() ;
        setss(id + 1, nums, arr, st) ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()) ;
        set<vector<int>> st ;
        vector<int> arr ;
        vector<vector<int>> res ;
        setss(0, nums, arr, st) ;
        for (auto &x : st) res.push_back(x) ;
        return res ;
    }
};