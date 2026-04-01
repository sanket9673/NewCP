class Solution {
public:
    bool isPowerOfThree(int n) {
        // largest n value in int(19) --> 3^19
        // every n=3^x where (x = 1,2,3,4,5..19) is able to divide 3^19 perfectly
        // 3^19 = 1162261467
        return (n > 0 && 1162261467 % n == 0) ;
    }
};