#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res(2) ;
        int a, b ;
        a = n / 2 ;
        b = n - a ;
        string a1 = to_string(a) ;
        string b1 = to_string(b) ;
        while (a1.contains('0') || b1.contains('0')) {
            int x = stoi(a1) ;
            int y = stoi(b1) ;
            x--;
            y++ ;
            a1 =to_string(x) ;
            b1 = to_string(y) ;
        }
        res[0] = stoi(a1) ;
        res[1] = stoi(b1) ;
        return res ;

        // optimized
        // class Solution {
        // public:
        //     int countZeros(long long n) {
        //     if (n == 0) return 1; // special case
        //     int count = 0;
        //     while (n > 0) {
        //         if (n % 10 == 0) count++;
        //         n /= 10;
        //     }
        //     return count;
        // }
        //     vector<int> getNoZeroIntegers(int n) {
        //         vector<int> ans;
        //         for (int i = 1; i < n; i++) {
        //             if (countZeros(i) == 0 && countZeros(n-i)==0){
        //                 ans = {i, n-i};
        //                 break;
        //             }
        //         }
        //         return ans;
        //     }
        // };
    }
};