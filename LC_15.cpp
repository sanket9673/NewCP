class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // pointes to be noted:
        // 1. nums[i] == nums[i-1] ---> same triplet, skip
        // 2. nums[i] > 0 ---> no tripet as sum wont be 0, break
        // 3. nums[i] + nums[left] + nums[right] = 0 (This reduces 3-sum into 2-sum)
        // 4. 2 pointers (left and right) also skip all duplicates
        // -> sum small - left++ else right-- ;
        sort(nums.begin(), nums.end()) ;
        vector<vector<int>> res ;
        unordered_map<int, int> x ;
        for (int num : nums) x[num]++ ;
        // why < n-2 (till n-3) and not < n-1 (till n - 2)
        // i = 0 → left = 1 → right = n - 1  (valid)
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue ;
            else if (nums[i] > 0) break ;
            else {
                int ft = nums[i] ;
                // 2 - pointer approach
                // left = i + 1  ||||| right = n - 1
                int lft = i + 1, rgt = nums.size() - 1 ;
                while (lft < rgt) {
                    int sum = nums[lft] + nums[rgt] ;
                    int total = nums[i] + sum ;
                    if (total == 0) {
                        res.push_back({nums[i], nums[lft], nums[rgt]}) ;
                        lft++ ;
                        rgt-- ;
                        // skip duplicates
                        while (lft < rgt && nums[lft] == nums[lft - 1]) lft++;
                        while (lft < rgt && nums[rgt] == nums[rgt + 1]) rgt--;
                    }
                    else if (total < 0) lft++ ;
                    else rgt-- ;
                }
            }
        }
        return res ;

        // FUNCTION BUT SLOW AND INEFFICIENT    
        // sort(nums.begin(), nums.end()) ;
        // vector<vector<int>> res ;
        // unordered_map<int, int> x ;
        // set<vector<int>> result ;
        // for (int num : nums) x[num]++ ;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (i > 0 && nums[i] == nums[i-1]) continue ;
        //     int fst = nums[i] ;
        //     x[fst]-- ;
        //     for (int j = i + 1; j < nums.size(); j++) {
        //         int sec = nums[j] ;
        //         if (sec > 0) continue ;
        //         else {
        //             x[sec]-- ;
        //             int ans = -(fst + sec) ;
        //             if (x.count(ans) != 0 && x[ans] >= 1) {
        //                 vector<int> fnl_set = {fst, sec, ans} ;
        //                 sort(fnl_set.begin(), fnl_set.end()) ;
        //                 result.insert(fnl_set) ;
        //                 // res.push_back(fnl_set) ;
        //             }
        //             x[sec]++ ;
        //         }
        //     }
        //     x[fst]++ ;
        // }
        // for (auto sol : result) res.push_back(sol) ;
        // return res ;
    }
};