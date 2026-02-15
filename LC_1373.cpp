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
    int maxsum = 0 ;
    struct Info {
        bool isbst ;
        int mn ;
        int mx ;
        int sum ;
    } ;

    Info solve(TreeNode* root) {
        // base case
        if (root == nullptr) return {true, INT_MAX, INT_MIN, 0} ;
        
        Info left = solve(root -> left) ;
        Info right = solve(root -> right) ;
        
        // check if BST
        if (left.isbst && right.isbst && left.mx < root -> val && root -> val < 
        right.mn) {
            int currsum = root -> val + left.sum + right.sum ;
            maxsum = max(maxsum, currsum) ;

            // as it is bst
            return {true,
                    min(left.mn, root -> val),
                    max(right.mx, root -> val),
                    currsum
                };
            
        }

        // if not bst
        return {false, 0, 0, 0} ; // discard
    }

    int maxSumBST(TreeNode* root) {
        // check at node level and not recomputing again and again
        // from left : maxleft, sumleft, isbst(left root) == true
        // from right : maxright, sumright, isbst(right root) == true
        // at current node: check isbst(left) && isbst(right) && 
        // continuing .... && maxleft < root -> val < maxright
        // then take result = sum = sumLeft + sumRight + root->val
        solve(root) ;
        return maxsum ;
    }
};