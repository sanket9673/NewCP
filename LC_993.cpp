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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, int> mp ; // value : parent
        queue<TreeNode*> res ;
        res.push(root) ;
        mp[root -> val] = -1 ;
        while (!res.empty()) {
            int sz = res.size() ;
            unordered_set<int> st ;
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = res.front() ;
                res.pop() ;
                if (curr -> left != nullptr) {
                    res.push(curr -> left) ;
                    st.insert(curr -> left -> val) ;
                    mp[curr -> left -> val] = curr -> val ;
                }
                if (curr -> right != nullptr) {
                    res.push(curr -> right) ;
                    st.insert(curr -> right -> val) ;
                    mp[curr -> right -> val] = curr -> val ;
                }
            }
            if (st.count(x) != 0 && st.count(y) != 0 && mp[x] != mp[y]) return true ;
        }
        return false ;
    }
};