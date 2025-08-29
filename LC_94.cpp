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
    vector<int> inorderTraversal(TreeNode* root) {
        // iterative
        vector<int> res ;
        if (root == nullptr) return res ;
        stack<TreeNode*> st ;
        TreeNode* curr = root ;
        while (curr != nullptr || !st.empty()) {
            // go left as much possible
            while (curr != nullptr) {
                st.push(curr) ;
                curr = curr -> left ;
            }

            // process
            curr = st.top() ;
            st.pop() ;
            res.push_back(curr -> val) ;

            // right 
            curr = curr -> right ;
        }
        return res ;
    }
};