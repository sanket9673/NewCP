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
    void builderparent(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == nullptr) return ;
        // maintain parent
        mp[root] = parent ;
        builderparent(root -> left, root, mp) ;
        builderparent(root -> right, root, mp) ;
    }
    void togetnode(TreeNode* root, int& start, TreeNode*& startpoint) {
        if (root == nullptr) return ;
        if (root -> val == start) {startpoint = root; return;}
        togetnode(root -> left, start, startpoint) ;
        togetnode(root -> right, start, startpoint) ;
    }
    int amountOfTime(TreeNode* root, int start) {
        // traverse the tree - assume it as GRAPH  
        int dist = 0 ; // stores the time required
        queue<TreeNode*> qw ;
        unordered_set<TreeNode*> visited ;
        unordered_map<TreeNode*, TreeNode*> parent ;
        builderparent(root, nullptr, parent) ;
        
        // get node
        TreeNode* startpoint = nullptr ;
        togetnode(root, start, startpoint) ;
        qw.push(startpoint) ;
        visited.insert(startpoint) ;
        while (!qw.empty()) {
            int sz = qw.size() ; 
            bool spread = false;
            
            while (sz--) {
                // every node checked
                TreeNode* curr = qw.front() ;
                qw.pop() ;
                // left
                if (curr -> left && !visited.count(curr -> left)) {
                    visited.insert(curr -> left) ;
                    qw.push(curr -> left) ;
                    spread = true;
                }
                // right
                if (curr -> right && !visited.count(curr -> right)) {
                    visited.insert(curr -> right) ;
                    qw.push(curr -> right) ;
                    spread = true;
                }
                // parent (previous node)
                if (parent[curr] && !visited.count(parent[curr])) {
                    visited.insert(parent[curr]) ;
                    qw.push(parent[curr]) ;
                    spread = true;
                }
            }
            if (spread == true) dist++ ;
        }
        return dist ;
    }
};