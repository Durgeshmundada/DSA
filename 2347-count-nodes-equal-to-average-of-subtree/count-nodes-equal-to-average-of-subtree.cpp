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
int ans=0;
    int averageOfSubtree(TreeNode* root) {
        pair<int,int> s=check(root);
        return ans;
    }
    pair<int,int> check(TreeNode* root){
        if(root==nullptr){
            return {0,0};
        }
        pair<int,int> left = check(root->left);
        pair<int,int> right = check(root->right);

        int sum = left.first + right.first + root->val;

        int count = left.second + right.second + 1;

        if(sum / count == root->val) {
            ans++;
        }

        return {sum, count};

    }
};