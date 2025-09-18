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
        void flatten(TreeNode* root) {
            if (root == nullptr) return ;
            stack<TreeNode*> st ;
            if (root -> right != nullptr) st.push(root -> right) ;
            if (root -> left != nullptr) st.push(root -> left) ;
            while (!st.empty()) {
                TreeNode* curr = st.top() ;
                st.pop() ;
                if (curr -> right != nullptr) st.push(curr -> right) ;
                if (curr -> left != nullptr) st.push(curr -> left) ;
                root -> left = nullptr ;
                root -> right = curr ;
                root = curr ;
            }
        }
    };