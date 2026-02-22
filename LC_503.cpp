class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // monotonic decreasing stack top(small) and bottom(largest)
        unordered_map<int, int> res ;  // for string the {index - value} pair
        int n = nums.size() ;
        stack<int> st ; // store indices (decresing)
        for (int i = 0; i < 2*n ; i++) {
            int id = i % n ;
            if (st.empty() && i < n) {st.push(id) ; continue ;}
            while(!st.empty() && nums[st.top()] < nums[id]) {
                res[st.top()] = nums[id] ; // index - value
                st.pop() ;
            }
            if (i < n) st.push(id) ; // first pass
        }

        for (int i = 0; i < nums.size(); i++) {
            if (res.count(i) == 0) nums[i] = -1 ;
            else nums[i] = res[i] ;
        }
        
        return nums ;
    }
};