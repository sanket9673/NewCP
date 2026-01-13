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

        // FRAGILE CODE
        // if (head == nullptr || head -> next == nullptr) return head ;
        // ListNode* temp1 = head ;
        // int sz = 1 ;
        // while (temp1 -> next != nullptr) {
        //     temp1 = temp1 -> next ;
        //     sz++ ;
        // }
        // ListNode* temp = head ;
        // ListNode* last = temp1 ;
        // for (int i = 0 ; i < sz/2 ; i++) {
        //     if (temp -> next == last) break ;

        //     ListNode* mov = temp -> next ;
        //     temp -> next = mov -> next ;
        //     mov -> next = nullptr ;

        //     last -> next = mov ;
        //     last = mov;
            
        //     temp = temp -> next ;
        // }
        // return head ;
    }
};