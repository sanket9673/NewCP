/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void builder(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == nullptr) return ;
        // store in the map
        mp[root] = parent ;
        builder(root -> left, root, mp) ;
        builder(root -> right, root, mp) ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // in this problem we have to think the tree as GRAPH with maintain the PARENT NODE TOO
        unordered_map<TreeNode*, TreeNode*> parent ;
        builder(root, nullptr, parent) ;

        int dist = 0 ;
        queue<TreeNode*> qw; 
        unordered_set<TreeNode*> visited ;

        // push the target
        qw.push(target) ;
        visited.insert(target) ;

        while (!qw.empty()) {
            int sz = qw.size() ;
            if (dist == k) break ;

            while (sz--) {
                TreeNode* curr = qw.front() ;
                qw.pop() ;

                // left child
                if (curr -> left != nullptr && visited.count(curr -> left) == 0) { // child exist and is not visited
                    qw.push(curr -> left) ;
                    visited.insert(curr -> left) ;
                }

                // right child
                if (curr -> right && !visited.count(curr -> right)) {
                    qw.push(curr -> right) ;
                    visited.insert(curr -> right) ;
                }

                // parent
                if (parent[curr] && !visited.count(parent[curr])) {
                    qw.push(parent[curr]) ;
                    visited.insert(parent[curr]) ;
                }
            }
            dist++;   // AFTER finishing level
        }
        // storing result
        vector<int> res;
        while (!qw.empty()) {
            TreeNode* curr = qw.front() ;
            qw.pop() ;
            res.push_back(curr -> val) ;
        }
        return res ;
    }
};