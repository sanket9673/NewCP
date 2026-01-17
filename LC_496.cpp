class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // using monotonic decreasing stack
        stack<int> st ;
        unordered_map<int, int> res ;
        for (int i = 0; i < nums2.size(); i++) {
            if (st.empty()) st.push(nums2[i]) ;
            else {
                // decreasing monotonic stack
                // top(smallest) & bottom(largest)
                if (st.top() < nums2[i]) {
                    while (!st.empty() && st.top() < nums2[i]) {
                        res[st.top()] = nums2[i] ;
                        st.pop() ;
                    }
                    st.push(nums2[i]) ;
                }
                else st.push(nums2[i]) ;
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (res.count(nums1[i]) == 0) nums1[i] = -1 ;
            else nums1[i] = res[nums1[i]] ;
        }
        return nums1 ;
    }
};