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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> qw ;
        qw.push(root) ;
        int lvl = 0 ;
        while (!qw.empty()) {
            vector<TreeNode*> nodes ;
            int n = qw.size() ;

            for (int i = 0; i < n; i++) {
                TreeNode* ele = qw.front() ;
                qw.pop() ;
                nodes.push_back(ele) ;
                if (ele -> left != nullptr) qw.push(ele -> left) ;
                if (ele -> right != nullptr) qw.push(ele -> right) ;
            }

            // now check level
            if (lvl % 2 == 1) { // check odd level
                int l = 0, r = n - 1; 
                while (l < r) {
                    swap(nodes[l] -> val, nodes[r] -> val) ;
                    l++ ;
                    r-- ;
                }
            }
            lvl++ ;
        }
        return root ;
    }
};