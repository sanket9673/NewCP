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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0 ;
        ListNode* temp = head ;
        while (temp != nullptr) {
            count++ ;
            temp = temp -> next ;
        }
        if (count == 1) return nullptr ;
        temp = head ;
        for (int i = 0; i < count / 2 - 1; i++) {
            temp = temp -> next ;
        }
        ListNode* dlt = temp -> next ;
        temp -> next = dlt -> next ;
        dlt -> next = nullptr ;
        return head ;
    }
};