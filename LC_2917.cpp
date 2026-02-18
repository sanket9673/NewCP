class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        
        int result = 0;
        
        for (int bit = 0; bit < 32; bit++) {
            
            int count = 0;
            
            for (int num : nums) {
                if (num & (1 << bit)) {
                    count++;
                }
            }
            
            if (count >= k) {
                result |= (1 << bit);
            }
        }
        
        return result;
    }
};

// class Solution {
// public:
//     int findKOr(vector<int>& nums, int k) {
//         vector<string> res ;
//         string rst = "" ;
//         for (int x : nums) {
//             bitset<32> bs(x) ;
//             string st = bs.to_string(); // this reverses
//             // bitset<32>.to_string() gives:
//             //     index 0 → bit 31
//             //     index 31 → bit 0
//             res.push_back(st) ;
//         }

//         for (int i = 0; i < 32; i++) {
//             int count = 0 ;
//             for (int j = 0; j < res.size(); j++) {
//                 if (res[j][i] == '1') count++ ;
//             }
//             if (count >= k) rst += '1' ;
//             else rst += '0' ;
//         }

//         int rr = 0 ;
//         for (int i = rst.size() - 1; i >= 0; i--) {
//             int pp = rst.size() - i - 1;
//             if (rst[i] == '1') rr += (1 << pp) ;
//         }
//         return rr ;
//     }
// };