/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;    

class Solution {
public:
    void deleteNode(ListNode* node) {
        // head not allowed to access 
        
        // approach - copy all the elements before from the node given 
        ListNode* temp = node ;
        while (node -> next != nullptr) {
            node -> val = node -> next -> val ;
            node = node -> next ;
        }
        while (temp -> next -> next != nullptr) {
            temp = temp -> next ;
        }
        temp -> next = nullptr ;
    }
};