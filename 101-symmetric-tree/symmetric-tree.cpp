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
int check(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return 1;
        }
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return 0;
        }
        int left = check(p->left, q->right);
        if (left == 0) return 0;
        return check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* p) {
        if(p==nullptr){
            return true;
        }
        return check(p->left, p->right) == 1;
    }
};