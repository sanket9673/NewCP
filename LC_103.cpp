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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res ;
        if (root == nullptr) return res ;
        queue<TreeNode*> q ;
        q.push(root) ;
        q.push(nullptr) ;
        vector<int> smp ;
        int count = 0 ;
        while (q.size() > 1) {
            TreeNode* node = q.front() ;
            q.pop() ;
            if (node == nullptr) {
                q.push(nullptr) ;
                if (count % 2 != 0) reverse(smp.begin(), smp.end()) ;
                count++ ;
                res.push_back(smp) ;
                smp.clear() ;
                continue ;
            }
            smp.push_back(node -> val) ;
            if (node -> left != nullptr) q.push(node -> left) ;
            if (node -> right != nullptr) q.push(node -> right) ;
        }
        if (count % 2 != 0) reverse(smp.begin(), smp.end()) ;
        count++ ;
        res.push_back(smp) ;
        return res ;
    }
};