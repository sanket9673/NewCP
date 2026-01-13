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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next) return head ;
        // Approach - maintain 2 chairs - odd and even and then connect them at last ;
        ListNode* odd = head ;
        ListNode* even = head -> next ;
        ListNode* evenhead = even ;
       
        // check even because even is ahead of odd.
        while (even != nullptr && even -> next != nullptr) {
            odd -> next = even -> next ;
            odd = odd -> next ;
            even -> next = even -> next -> next ;
            even = even -> next ;
        }
        odd -> next = evenhead ;
        return head ;

        // FRAGILE CODE (Bugs present)
        // if (head == nullptr || head -> next == nullptr) return head ;
        // ListNode* temp1 = head -> next ;
        // ListNode* prev = head ;
        // int sz = 1 ;
        // while (temp1 -> next != nullptr) {
        //     prev = prev -> next ;
        //     temp1 = temp1 -> next ;
        //     sz++ ;
        // }
        // ListNode* temp = head ;
        // ListNode* last ;
        // bool evenlength = false ;
        // if (sz % 2 == 0) {
        //     sz = sz/2 - 1 ; 
        //     last = prev;
        //     evenlength = true ;
        // }
        // else {sz = sz/2 ; last = temp1;}
        // for (int i = 0 ; i <= sz ; i++) {
        //     ListNode* mov = temp -> next ;
        //     temp -> next = mov -> next ;
        //     mov -> next = nullptr ;
        //     last -> next = mov ;
        //     last = last -> next ;
        // }
        // if (evenlength == true) last -> next = temp1 ;
        // return head ;
    }
};