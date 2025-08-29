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
        vector<int> res ;
        if (root == nullptr) return res ;
        queue<TreeNode*> q ;
        q.push(root) ;
        while (!q.empty()) {
            int n = q.size() ;
            for (int i = 0; i < n; i++) {
                TreeNode* num = q.front() ;
                q.pop();
                res.push_back(num -> val) ;
                if (num -> left != nullptr) q.push(num -> left) ;
                if (num -> right != nullptr) q.push(num -> right) ;
            }
        }
        return res ;
    }
};