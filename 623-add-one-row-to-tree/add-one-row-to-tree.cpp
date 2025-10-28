class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Special case: insert a new root
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        // Recursive helper call
        addRow(root, val, 1, depth);
        return root;
    }

private:
    void addRow(TreeNode* node, int val, int currDepth, int targetDepth) {
        if (!node) return;

        // If we are one level above the target
        if (currDepth == targetDepth - 1) {
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);

            newLeft->left = node->left;
            newRight->right = node->right;

            node->left = newLeft;
            node->right = newRight;
            return;
        }

        // Recurse deeper
        addRow(node->left, val, currDepth + 1, targetDepth);
        addRow(node->right, val, currDepth + 1, targetDepth);
    }
};
