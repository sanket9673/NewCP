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
    vector<int> preorderTraversal(TreeNode* root) {
        // Recursive approach
        // vector<int> res ;
        // if (root == nullptr) return res ; 
        // int x = root -> val ;
        // res.push_back(x) ;
        // vector<int> l = preorderTraversal(root -> left) ;
        // vector<int> r = preorderTraversal(root -> right) ;
        // res.insert(res.end(), l.begin(), l.end()) ;
        // res.insert(res.end(), r.begin(), r.end()) ;
        // return res ;

        // Iterative apporach
        vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            res.push_back(node->val);   // root first

            if (node->right) st.push(node->right); // push right first
            if (node->left) st.push(node->left);   // then left (so left is processed first)
        }
        return res;
    }
};
