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
        levelOrderRec(root->left,root->right,1);
        return root;
    }
    void levelOrderRec(TreeNode* leftN,TreeNode* rightN, int level) {
    // Base case
    if (leftN == nullptr || rightN==nullptr) return;
    if(level%2==1){
        swap(leftN->val,rightN->val);
    }
    // Recur for left and right children
    levelOrderRec(leftN->left, rightN->right, level + 1);
    levelOrderRec(leftN->right, rightN->left, level + 1);
}
};