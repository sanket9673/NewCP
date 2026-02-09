class Solution {
public:
    void pre(vector<int>& nums, int id, vector<vector<int>>& res, vector<int>& curr, vector<bool>& used) {
        if (id == nums.size()) {  
            res.push_back(curr) ;      
            return;
        }
        // travelling over all elements in keeping track
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue ;
            else {
                used[i] = true ;
                curr.push_back(nums[i]) ;
                // backtrack
                pre(nums, id+1, res, curr, used) ;
                curr.pop_back() ;
                // after completing all premutate on 1 then make it false for the next iteration
                used[i] = false ;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res ;
        vector<int> curr ;
        vector<bool> used(nums.size(), false) ;
        pre(nums, 0, res, curr, used) ;
        return res ;
    }
};