class Solution {
  public:
    bool possible(vector<int> arr, int k, int pages) {
        int pag = arr[0], student = 1 ;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > pages) return false ; // too big
            if (pag + arr[i] <= pages) pag += arr[i] ;
            else {
                pag = arr[i] ;
                student++ ;
            }
        }
        // to check : Did we need more than k students?
        return (student > k) ? false : true ;
    }
    int findPages(vector<int> &arr, int k) {
        
        // We are doing this:

        // “Suppose a student is allowed to read at most X pages.
        // Can I assign all books to at most k students (contiguously)?”

        // Minimize the maximum
        if (arr.size() < k) return -1 ;
        // no sort (contiguous needed) -> sort(arr.begin(), arr.end()) ;
        if (arr.size() == k) return *max_element(arr.begin(), arr.end()) ; 
        // low = max(arr) and high = sum(arr)
        int low = *max_element(arr.begin(), arr.end()) ;
        int high = 0 , result = INT_MAX ;
        for (int x : arr) high += x ;
        while (low <= high) {
            int mid = low + (high - low) / 2 ;
            // Per student if atmost X pages are allowed to read
            // if we get answer we need to string the window
            bool found = possible(arr, k, mid) ;
            if (found == true) {
                result = min(mid, result) ;
                high = mid - 1 ;
            }
            else low = mid + 1 ;
        }
        return result ;
    }
};