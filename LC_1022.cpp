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
    // void binary(vector<int>& res, int ans, TreeNode* root) {
    //     if (root == nullptr) return ;
    //     // build number
    //     ans = ans * 10 + (root -> val) ;

    //     // when leaf encountered --> store
    //     if (!root -> left && !root -> right) {
    //         res.push_back(ans) ;
    //         return ;
    //     }

    //     binary(res, ans, root -> left) ;
    //     binary(res, ans, root -> right) ;
    // }
    // int binarytodecimal(int num) {
    //     int res = 0, i = 0 ;
    //     while (num > 0) {
    //         res += (num % 10) * pow(2, i) ; 
    //         num /= 10 ;
    //         i++ ;
    //     }
    //     return res ;
    // }
    int dfs(TreeNode* root, int curr) {
        if (!root) return 0 ;
        curr = curr * 2 + root -> val ;
        // check leaf
        if (!root -> left && !root -> right) return curr ;

        return dfs(root -> left, curr) + dfs(root ->right, curr) ;
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0) ;
        // vector<int> res ;
        // int ans = 0 ;
        // binary(res, ans, root) ;
        // int result = 0 ;
        // for (int num : res) {
        //     cout << num << " " << endl ;
        //     result += binarytodecimal(num) ;
        // }
        // return result ;
    }
};