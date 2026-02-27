class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return sumr(root, 0);
    }

    int sumr(TreeNode* root, int result) {
        if (root == nullptr) return 0;

        result = result * 2 + root->val;

        // ONLY valid stopping point
        if (root->left == nullptr && root->right == nullptr) {
            return result;
        }

        return sumr(root->left, result) +
               sumr(root->right, result);
    }
};