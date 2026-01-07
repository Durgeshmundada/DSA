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
long long mod = 1000000007;
    long long totalSum = 0;
    long long ans = 0;
    int maxProduct(TreeNode* root) {
        up(root);
        totalSum=root->val;
        maxp(root);
        return ans%mod;
    }
    void up(TreeNode* root){
        if (root == nullptr) return;

        up(root->left);
        up(root->right);

        int leftSum = (root->left ? root->left->val : 0);
        int rightSum = (root->right ? root->right->val : 0);

        root->val = root->val + leftSum + rightSum;
    }
    void maxp(TreeNode* root){
        if (root == nullptr) return;

        if (root->left != nullptr) {
            long long part = root->left->val;
            ans = max(ans, part * (totalSum - part));
        }

        if (root->right != nullptr) {
            long long part = root->right->val;
            ans = max(ans, part * (totalSum - part));
        }

        maxp(root->left);
        maxp(root->right);
    }
};