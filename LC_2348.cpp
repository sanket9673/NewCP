#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, res = 0 ;
        for (int x : nums) {
            if (x == 0) count++ ;
            else {
                res += count ;
                res += (count*(count-1)) / 2 ;
                count = 0 ;
            }
        }  
        if (count > 0) {
            res += count ;
            res += (count*(count-1)) / 2 ;
        }
        return res ; 
    }
};