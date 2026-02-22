class Solution {
public:
    using ll = long long ;
    int nextGreaterElement(int n) {
        if (n == -1) return -1 ;
        string s = to_string(n) ;
        int pivot = -1 ;
        for (int i = s.length() - 2; i >= 0; i--) {
            int x = s[i] - '0', y = s[i+1] - '0' ;
            if (x < y) {pivot = i; break ;} // got the element that is less
        }   

        if (pivot == -1) return -1 ; // number's digit is strictly decreasing

        // check the whole right which is larger to swap (next greatest only)
        for (int i = s.length() - 1; i >= pivot + 1; i--) {
            if (s[i] > s[pivot]) {swap(s[pivot], s[i]); break;} // swapping
        }

        reverse(s.begin() + pivot + 1, s.end()) ; 
        // from reversing pivot + 1 to the end
        ll ans = stoll(s) ;
        if (ans > INT_MAX) return -1 ;
        return (int)ans ;
    }
};