#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> res ;
        int count1 = 0, count0 = 0 ;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (count1 != 0) {
                    res.push_back(count1) ;
                    count1 = 0 ;
                }
                count0++ ;
            }
            else {
                if (count0 > 1) {
                    res.push_back(0) ;
                }
                count0 = 0 ;
                count1++ ;
            }
        }
        if (count1 > 0) res.push_back(count1) ;

        if (count0 == nums.size()) return 0 ; // edge case [0,0,0,0]
        if (count1 == nums.size()) return nums.size() - 1 ;
        if (res.size() == 1) return res[0]; // edge case [1,1,1,1]

        int result = INT_MIN ;

        for (int x : res) cout << x << " " << endl ;

        cout << " " << endl ;

        for (int i = 0; i < res.size() - 1; i++) {
            int sample = res[i] + res[i+1] ;
            result = max(result, sample) ;
            cout << sample << " "  << result << " " << endl ;
        }

        return result ;
        // WRONG CODE
        // queue<int> id ;
        // for (int i = 0; i < nums.size()-1; i++) {
        //     if (nums[i] == 0 && nums[i+1] == 1) id.push(i+1) ;
        // }
        // int mxlength = INT_MIN, count ;
        // if (id.empty()) return nums.size() - 1 ;
        // while (!id.empty()) {
        //     count = 0 ;
        //     int newid = id.front() ;
        //     id.pop() ;
        //     bool zerofnd = false ;
        //     for (int i = newid; i < nums.size(); i++) {
        //         if (nums[i] == 0 && zerofnd == false) {
        //             zerofnd = true ;
        //             continue ;
        //         }
        //         else if (nums[i] == 0 && zerofnd == true) break ;
        //         else count++ ;
        //     }
        //     cout << count << endl ;
        //     mxlength = max(mxlength, count) ;
        // }
        // mxlength = max(mxlength, count) ;
        // return mxlength ;
    }
};