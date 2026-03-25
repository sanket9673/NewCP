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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0 ;
        ListNode* temp = head ;
        while (temp != nullptr) {n++ ; temp = temp -> next;}
        if (n < k) return head ;
        ListNode* dummy = new ListNode(0) ;
        stack<ListNode*> st ;
        temp = head ;
        ListNode* nxt = dummy ;
        int cnt = 1 ;
        while (temp != nullptr) {
            st.push(temp) ;
            temp = temp -> next ;
            if (st.size() == k) {
                while (!st.empty()) {
                    ListNode* ele = st.top() ;
                    st.pop() ;
                    nxt -> next = ele ;
                    nxt = nxt -> next ;
                    nxt -> next = temp ;
                }
            }
        } 
        head = dummy -> next ;
        return head ;
    }
};