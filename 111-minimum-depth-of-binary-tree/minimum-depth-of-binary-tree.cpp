class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        // If no left child, must go right
        if (root->left == nullptr) 
            return 1 + minDepth(root->right);
        
        // If no right child, must go left
        if (root->right == nullptr) 
            return 1 + minDepth(root->left);

        // Both children exist, take the smaller depth
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
