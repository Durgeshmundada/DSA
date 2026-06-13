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
    int rob(TreeNode* root) {
        pair<int,int> r=solve(root);
        return max(r.first,r.second);

    }
    pair<int,int> solve(TreeNode* root){
        if(root==nullptr) return {0,0};
        auto left = solve(root->left);
        auto right = solve(root->right);
        auto take= root->val+left.second+right.second;
        auto skip=max(left.first, left.second) +
                   max(right.first, right.second);
        return {take,skip};
    }
};