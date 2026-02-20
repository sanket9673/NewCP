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
    void inorder(TreeNode* root, vector<int>& res) {
        if (root == nullptr) return ;
        inorder(root -> left, res) ;
        res.push_back(root -> val) ;
        inorder(root -> right, res) ;
    }
    void chk(TreeNode* root, unordered_map<int, int>& mp) {
        if (root == nullptr) return ;
        if (mp.count(root -> val) != 0) {
            root -> val = mp[root -> val] ;
        }
        chk(root -> left, mp) ;
        chk(root -> right, mp) ;
    }
    void recoverTree(TreeNode* root) {
        vector<int> res ;
        inorder(root, res) ;
        vector<int> smp(res.begin(), res.end()) ;
        sort(smp.begin(), smp.end()) ;
        unordered_map<int, int> mp ;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] != smp[i]) {
                mp[res[i]] = smp[i] ;
                mp[smp[i]] = res[i] ;
                // dont break here, might be more than one voilations
            }
        }
        chk(root, mp) ;
    }
};