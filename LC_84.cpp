class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // solution 1 : 
        // calculate next smallest element(array) and prev smallest elment (array)
        // then for each i : do arr[i] * (nse[i]-pse[i]-1)

        stack<int> st ;
        // stack stores the indices not values
        // bar stop expading area when bar size < current bar 
        // monotonic increasing stack (storing indices)
        int area = 0; 
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                // we are chooding st.top value because we are at that value and the i-th value we will push at the end so technically we are computing for st.top value
                int height = heights[st.top()] ; 
                st.pop() ;
                int nse = i ; // what we have currently after pop
                int pse = st.empty() ? -1 : st.top() ;
                int width = nse - pse - 1 ;
                area = max(area, height * width) ; 
            }
            st.push(i) ;
        }

        // if stack still have elements
        while (!st.empty()) {
            int height = heights[st.top()] ;
            st.pop() ;
            int nse = heights.size();
            int pse = st.empty() ? -1 : st.top() ;
            int width = nse - pse - 1 ;
            area = max(area, height * width) ;
        }

        return area ;
        // when popping
            // height = heights[i]
            // right  = current_index
            // left   = stack.top()   (after pop)
            // width  = right - left - 1
            // area   = height × width
            
    }
};