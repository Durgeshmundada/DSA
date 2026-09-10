class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(check(root, 0, limit))
            return nullptr;

        return root;
    }

    bool check(TreeNode* root, int sum, int limit) {
        if(root == nullptr)
            return true;

        sum += root->val;

        if(root->left == nullptr && root->right == nullptr) {
            return sum < limit;
        }

        bool left = check(root->left, sum, limit);
        bool right = check(root->right, sum, limit);

        if(left)
            root->left = nullptr;

        if(right)
            root->right = nullptr;

        return left && right;
    }
};