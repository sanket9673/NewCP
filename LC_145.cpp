/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // iterative
        vector<int> res ;
        if (root == nullptr) return res ;
        stack<TreeNode*> st1 ;
        st1.push(root) ;
        stack<TreeNode*> st2 ;
        while (!st1.empty()) {
            TreeNode* curr = st1.top() ;
            st1.pop();
            st2.push(curr) ;

            if (curr -> left != nullptr) st1.push(curr -> left) ;
            if (curr -> right != nullptr) st1.push(curr -> right) ;

            // we made --> root right left
            // after reverse(from st2) we get ---> left right root (postorder)
        }

        while (!st2.empty()) {
            TreeNode* peek = st2.top() ;
            st2.pop() ;
            res.push_back(peek -> val) ;
        }
        return res ;
    }
};