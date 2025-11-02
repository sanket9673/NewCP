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
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head ;
        ListNode *prev = nullptr, *curr = head ;
        
        // reversing and solving -> A.S = O(1)
        while (curr != nullptr) {
            ListNode* next = curr -> next ; // next occ of curr node
            curr -> next = prev ;
            prev = curr ;
            curr = next ;
        }
        ListNode *dummy = new ListNode(-1) ;
        ListNode *temp = dummy ;
        curr = prev ; // prev is pointing to last node (ex. 8) 
        while (curr != nullptr) {
            if (curr -> val >= temp -> val) {
                temp -> next = curr ;
                temp = curr ;
                curr = curr -> next ;
            }
            else curr = curr -> next ;
        }
        temp -> next = nullptr ; // last node pointing nullptr

        prev = nullptr ;
        curr = dummy -> next ; // new pointer to new head (DUMMY)
        while (curr != nullptr) {
            ListNode *next = curr -> next ;
            curr -> next = prev ;
            prev = curr ;
            curr = next ;
        }
        return prev ;

        // SOLUTION WITH VECTOR ARRAY
        // vector<int> res ;
        // ListNode* temp = head ;
        // while (temp != nullptr) { res.push_back(temp -> val) ; temp = temp -> next ; }
        // int n = INT_MIN ;
        // for (int i = res.size() - 1; i >= 0; i--) {
        //     if (res[i] >= n) n = res[i] ;
        //     else res.erase(res.begin() + i) ;
        // }
        // temp = head ;
        // int i = 0 ;
        // while (temp != nullptr && i < res.size() - 1) {
        //     temp -> val = res[i] ;
        //     temp = temp -> next ;
        //     i++ ;
        // }
        // temp -> val = res[res.size() - 1] ;
        // temp -> next = nullptr ;
        // return head ;
    }
};