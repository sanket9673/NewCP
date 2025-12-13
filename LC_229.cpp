class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res ;
        int cand1 = -1, cand2 = -1, count1 = 0, count2 = 0 ;
        // MOORE VOTING 
        // for n/k ----> atmost K-1 elements should ne there
        // candidate identification
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == cand1) count1++ ;
            else if (nums[i] == cand2) count2++ ;
            else if (count1 == 0) {count1++ ; cand1 = nums[i] ;}
            else if (count2 == 0) {count2++ ; cand2 = nums[i] ;}
            else {
                count1-- ;
                count2-- ;
            }
        }

        // candidate verification
        count1 = 0, count2 = 0 ;
        for (int x : nums) {
            if (x == cand1) count1++ ;
            else if (x == cand2) count2++ ;
        }

        if (count1 > nums.size() / 3) res.push_back(cand1) ;
        if (count2 > nums.size() / 3) res.push_back(cand2) ;

        return res ;
    }
};