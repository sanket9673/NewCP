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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr) return head ;
        int n = 0 ;
        ListNode* prev1 = nullptr ;
        ListNode* prev2 = nullptr ;
        ListNode* temp1 = head ;
        while (temp1 != nullptr) {
            temp1 = temp1 -> next ;
            n++ ;
        }
        if (k == n - k + 1) return head ;
        temp1 = head ;
        ListNode* temp2 = head ;
        for (int i = 1; i < k; i++) {
            prev1 = temp1 ;
            temp1 = temp1 -> next ;
        }
        for (int i = 1; i < n - k + 1; i++) {
            prev2 = temp2 ;
            temp2 = temp2 -> next ;
        }

        // prev1 and prev2 can be nullpr
        if (prev1) prev1 -> next = temp2 ;
        if (prev2) prev2 -> next = temp1 ;

        // swap 
        ListNode* nxt = temp1 -> next ;
        temp1 -> next = temp2 -> next ;
        temp2 -> next = nxt ;

        // if head involved
        if (k == 1) return temp2 ;
        if (k == n) return temp1 ;

        return head ;

        // ListNode* nx1 = temp1 -> next ;
        // ListNode* nx2 = temp2 -> next ;
        // temp2 -> next = nx1 ;
        // temp1 -> next = nx2 ;
        // return dummy -> next;
    }
};