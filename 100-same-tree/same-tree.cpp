class Solution {
public:
    int check(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return 1;
        }
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return 0;
        }
        int left = check(p->left, q->left);
        if (left == 0) return 0;
        return check(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q) == 1;
    }
};
