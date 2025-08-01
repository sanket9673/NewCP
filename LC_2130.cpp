#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> res ;
        ListNode* temp = head ;
        while (temp != nullptr) {
            int num = temp -> val ;
            res.push_back(num) ;
            temp = temp -> next ;
        }
        int p = 0, q = res.size() - 1, result = 0 ;
        while (p < q) {
            int sum = res[p] + res[q] ;
            result = max(result, sum) ;
            p++ ; 
            q-- ;
        }
        return result ;
    }
};