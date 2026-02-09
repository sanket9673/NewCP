class Solution {
public:
    void backtrack(int n, int k, vector<vector<int>>& res, vector<int>& curr, int id, vector<bool>& used) {
        if (curr.size() == k) {
            res.push_back(curr) ;
            return ;
        }
        for (int i = id; i < n; i++) {
            if (!used[i]) {
                used[i] = true ;
                curr.push_back(i + 1) ; // 0-index --> 1-index
                // recursive call
                backtrack(n, k, res, curr, i + 1, used) ;
                // backtrack
                used[i] = false ;
                curr.pop_back() ;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res; 
        vector<bool> used(n, false) ;
        vector<int> curr ;
        backtrack(n, k, res, curr, 0, used) ;
        return res ;
    }
};