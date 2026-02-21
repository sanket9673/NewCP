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
    TreeNode* build(vector<int>& nums, int l, int r) {
        if (l > r) return nullptr ; // l == r means one element exists
        TreeNode* root = new TreeNode(nums[l]) ;
        int mid = r + 1 ;
        for (int i = l + 1; i <= r; i++) {
            if (nums[l] < nums[i]) {mid = i; break;}
        }
        root -> left = build(nums, l+1, mid - 1) ;
        root -> right = build(nums, mid, r) ;
        return root ;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, 0, preorder.size() - 1) ;
    }
};