class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        unordered_map<int, vector<string>> mp ;
        set<int> st ;
        int n = nums.size() ;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i].length()) ;
            mp[nums[i].length()].push_back(nums[i]) ;
        }

        // to store result of sorted array
        vector<string> res ;
        for (const int& ele : st) {
            sort(mp[ele].begin(), mp[ele].end()) ;
            res.insert(res.end(), mp[ele].begin(), mp[ele].end()) ;
        }
        return res[n - k] ;
    }
};