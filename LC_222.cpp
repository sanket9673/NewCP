#include <bits/stdc++.h>
using namespace std ;

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
    int countNodes(TreeNode* root) {
        // approach (best - o((logn)^2)
        if (root == nullptr) return 0 ;
        int hl = 0, hr = 0 ;
        TreeNode* l = root ;
        TreeNode* r = root ;

        while (l != nullptr) {hl++ ; l = l -> left ;}
        while (r != nullptr) {hr++ ; r = r -> right ;}
        
        if (hl == hr) return pow(2, hl) - 1 ;
        else return 1 + countNodes(root -> left) + countNodes(root -> right) ;

        // Alternate method o(n)
        // if (root == nullptr) return 0 ;
        // return 1 + countNodes(root -> left) + countNodes(root -> right) ;

        // Alternate method o(n)
        // if (root == nullptr) return 0 ;
        // int count = 1, l = 0, r = 0 ;
        // if (root -> left != nullptr) {
        //     l = countNodes(root -> left) ;
        // }
        // if (root -> right != nullptr){
        //     r = countNodes(root -> right) ;
        // }
        // return count + l + r ;
    }
};