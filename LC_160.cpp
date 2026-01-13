/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // here the common attribute is NOT VALUE
        // common attribute of the NODE ITSELF

        // for S.C = O(1), we need to find len1 and len2, find postive difference and move smaller to same like larger adding dummy nodes and CHECKING IF THERE ANY INTERSECTION.

        // TWO node with same values may not be same (diff address may be there for that node)
        unordered_set<ListNode*> sp ;
        if (headA == nullptr || headB == nullptr) return nullptr ;
        ListNode* temp = headA ;
        while (temp != nullptr) {
            sp.insert(temp) ;
            temp = temp -> next ;
        }
        temp = headB ;
        while (temp != nullptr) {
            if (sp.count(temp) != 0) return temp ;
            temp = temp -> next ;
        }
        return nullptr ;
    }
};