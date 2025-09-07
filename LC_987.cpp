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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // idea = we need to store {value, index(mapping), level}

        
        // Bfs idea code written blow
        vector<vector<int>> res ;
        map<int, vector<pair<int, int>>> mp ;
        // map = [column(index) , {value, level}]

        if (root == nullptr) return res ;

        queue<tuple<TreeNode*, int, int>> q ;
        // queue = [node, column(index, level)]

        q.push({root, 0, 0}) ;

        while (!q.empty()) {
            auto [node, id, level] = q.front();
            q.pop() ;
        
            mp[id].push_back({node -> val, level}) ;

            if (node -> left != nullptr) {
                q.push({node -> left, id - 1, level + 1}) ; // not level++ == mutates original value
            }
            if (node -> right != nullptr) {
                q.push({node -> right, id + 1, level + 1}) ;
            }
        }

        // map = [column(index) , {value, level}]
        for (auto &[col, vec] : mp) {
            sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                if (a.second != b.second) return a.second < b.second ; // smaller lvl frst
                return a.first < b.first ; // smaller val first
            }) ;

            vector<int> colVals;
            colVals.reserve(vec.size()); // preallocation (performance optimization)
            for (auto &p : vec) colVals.push_back(p.first);
            res.push_back(move(colVals));
        }

        return res ;
    }
};